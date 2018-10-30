#include "WorkThread.h"
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include "MvCameraControl.h"
#include "MyCamera.h"
#include <vector>
#include "Solution.h"

using namespace std;

WorkThread::WorkThread()
{
	getPara(inputThresh, minPixNumber, inExposureTime);
	stImageInfo = { 0 };

}


WorkThread::~WorkThread()
{
}

void WorkThread::findRect(cv::Mat &src, cv::Mat &dst)
{
	//找到轮廓的最小包围边框，并画出包围矩形
	//输入为二值图
	cv::Mat src_2; cv::Mat temp1;
	src.copyTo(src_2);
	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> hierarchy;
	findContours(src_2, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	vector<cv::Rect> boundRect(contours.size());  //定义一个矩形类集合

	for (int i = 0; i < contours.size(); i++)
	{
		//drawContours(imageROI, contours, i, Scalar(0,0,255), 1, 8); //画出轮廓
		boundRect[i] = cv::boundingRect(cv::Mat(contours[i]));

		//删除过小的矩形
		if (boundRect[i].width > (src_2.cols - 100) || boundRect[i].height < 10 || boundRect[i].area() < 10)
			continue;

		//删除宽高比过小的矩形
		//double proportion = boundRect[i].width / boundRect[i].height;
		//	if (proportion < 1)
		//	continue;

		//画出矩形包围框，rect.tl(),为矩形类左上点坐标，rect.br()为左下点的坐标
		//drawContours(dst, contours, i, Scalar(0, 0, 255), -1, 8); //画出轮廓
		rectangle(dst, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 2, 8, 0);
		//temp1.copyTo(dst);
	}
}

int WorkThread::closeDevice(void)
{
	if (m_pcMyCamera)
	{
		m_pcMyCamera->Close();
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
	}

	m_bOpenDevice = FALSE;
	m_bStartGrabbing = FALSE;

	if (m_pBufForDriver)
	{
		free(m_pBufForDriver);
		m_pBufForDriver = NULL;
	}
	m_nBufSizeForDriver = 0;

	if (m_pBufForSaveImage)
	{
		free(m_pBufForSaveImage);
		m_pBufForSaveImage = NULL;
	}
	m_nBufSizeForSaveImage = 0;
	return MV_OK;
}


void SendMsg(std::string msg)
{
	char appname[] = "vcloud";
	const size_t cSize = strlen(appname) + 1;
	WCHAR * wc = new WCHAR[cSize];
	mbstowcs(wc, appname, cSize);
	HWND hWnd = ::FindWindow(NULL, wc);
	if (hWnd != NULL)
	{
		HWND hSendWindow = GetConsoleWindow();
		COPYDATASTRUCT CopyData;
		char szSendBuf[1024];
		strcpy_s(szSendBuf, msg.c_str());
		CopyData.dwData = 1;
		CopyData.cbData = strlen(msg.c_str());
		CopyData.lpData = szSendBuf;
		auto i = SendMessage(hWnd, WM_COPYDATA, (WPARAM)hSendWindow, (LPARAM)&CopyData);
	}
	delete[]wc;
}

int WorkThread::openDevice(void)
{
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

	// ch:枚举子网内所有设备 | en:Enumerate all devices within subnet
	int nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		qDebug() << "enum device failed." << endl;
		emit returnInfo("enum device failed.");
		return STATUS_ERROR;
	}

	if (m_stDevList.nDeviceNum > 0)
	{
		for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++)
		{
			qDebug() << "[device " << i << "]";
			emit returnInfo("[device " + std::to_string(i) + "]");
			MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
			if (NULL == pDeviceInfo)
			{
				qDebug() << "deviceInfo is NULL";
				emit returnInfo("deviceInfo is NULL");
				return STATUS_ERROR;
			}
		}
	}
	else
	{
		qDebug() << "Find No Devices!\n";
		emit returnInfo("Find No Devices!");
		return STATUS_ERROR;
	}

	unsigned int nIndex = 0;

	// ch:由设备信息创建设备实例 | en:Device instance created by device information
	if (NULL == m_stDevList.pDeviceInfo[nIndex])
	{
		qDebug() << "Device does not exist";
		emit returnInfo("Device does not exist");
		return STATUS_ERROR;
	}

	m_pcMyCamera = new CMyCamera;
	if (NULL == m_pcMyCamera)
	{
		return STATUS_ERROR;
	}

	nRet = m_pcMyCamera->Open(m_stDevList.pDeviceInfo[nIndex]);
	if (MV_OK != nRet)
	{
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
		qDebug() << " open Camera failed. Camera is in use.";
		emit returnInfo("open Camera failed. Camera is in use.");
		return STATUS_ERROR;
	}
	else
	{
		qDebug() << "Camera opened";
		emit returnInfo("Camera opened");
	}

	// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
	if (m_stDevList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE)
	{
		int nPacketSize = m_pcMyCamera->GetOptimalPacketSize();
		if (nPacketSize > 0)
		{
			nRet = m_pcMyCamera->SetIntValue("GevSCPSPacketSize", nPacketSize);
			if (nRet != MV_OK)
			{
				qDebug() << "Warning: Set Packet Size fail!";
				emit returnInfo("Camera opened");
			}
		}
		else
		{
			qDebug() << "Warning: Get Packet Size fail!";
			emit returnInfo("Warning: Get Packet Size fail!");
			return STATUS_ERROR;
		}
	}
	return MV_OK;
}

void WorkThread::run()
{
	int nRet = openDevice();
	if (nRet != MV_OK)
	{
		qDebug() << "open device failed." << endl;
		emit returnInfo("open device failed.");
		return;
	}

	//设置相机图像的像素格式
	nRet = m_pcMyCamera->SetEnumValue("PixelFormat", nValue);   // PixelType_Gvsp_RGB8_Packed 或 PixelType_Gvsp_Mono8
	if (nRet != MV_OK)
	{
		emit returnInfo("set PixelType failed. ");
	}
	emit returnInfo("PixelType set successed. ");

	//开始取流
	if (NULL != m_pcMyCamera)
	{
		nRet = m_pcMyCamera->StartGrabbing();
		m_bStartGrabbing = TRUE;
		if (nRet == MV_OK)
		{
			qDebug() << "start grabbing...";
			emit returnInfo("start grabbing...");
			//m_hwndDisplay = (HWND)ui.label->winId();
			//nRet = m_pcMyCamera->Display(m_hwndDisplay);
		}
	}
	else
	{
		qDebug() << "mpcMyCamera is NULL";
		emit returnInfo("mpcMyCamera is NULL");
		return;
	}

	//保存图片
	// ch:获取1张图 | en:get one image
	unsigned int nRecvBufSize = 0;
	nRet = MV_OK;

	// ch:仅在第一次保存图像时申请缓存，在 CloseDevice 时释放
	// en:Request buffer only when save image for first time, release after CloseDevice
	if (NULL == m_pBufForDriver)
	{
		// ch:从相机中获取一帧图像大小 | en:Get size of one frame from camera
		nRet = m_pcMyCamera->GetIntValue("PayloadSize", &nRecvBufSize);
		if (nRet != MV_OK)
		{
			qDebug() << "failed in get PayloadSize";
			emit returnInfo("failed in get PayloadSize");
			return;
		}
		else
		{
			qDebug() << "get payloadsize";
			emit returnInfo("get payloadsize");
		}
		// ch:一帧数据大小
		// en:One frame size
		m_nBufSizeForDriver = nRecvBufSize;
		m_pBufForDriver = (unsigned char *)malloc(m_nBufSizeForDriver);
		if (NULL == m_pBufForDriver)
		{
			qDebug() << "malloc m_pBufForDriver failed, run out of memory";
			emit returnInfo("malloc m_pBufForDriver failed, run out of memory");
			return;
		}
	}

	//MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

	unsigned int nDataSize = nRecvBufSize;
	unsigned int nImageNum = 1;
	unsigned int nDataLen = 0;

	while (nImageNum)
	{
		nRet = m_pcMyCamera->GetOneFrameTimeout(m_pBufForDriver, &nDataLen, m_nBufSizeForDriver, &stImageInfo, 5000);
		if (nRet == MV_OK)
		{
			//设置曝光时间
			nRet = SetExposureTime(inExposureTime);
			if (nRet != MV_OK)
			{
				emit returnInfo("set ExposureTime failed. ");
			}

			cv::Mat src(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC3, m_pBufForDriver);

			//************* image processing here *****************//
			cv::Mat imNonZeroNum, imBw, srcWithRect, roiOfCharacter;
			int ZeroNum = solu.calNonZero(src, imNonZeroNum, inputThresh);
			emit returnRes(std::to_string(ZeroNum));
			solu.norThresh(src, imBw, inputThresh);
			src.copyTo(srcWithRect);
			solu.findRect(imBw, srcWithRect, roiOfCharacter);
			solu.findLine(imBw, srcWithRect);
			//solu.figShow("imWithRect", srcWithRect);
			//cv::waitKey(20);
			if (roiOfCharacter.data)
			{
				solu.figShow("roiOfCharater", roiOfCharacter);
				cv::imwrite("roi.jpg", roiOfCharacter);
				cv::waitKey(20);
			}
			if (showSrc == true)
			{
				if (srcWithRect.channels() == 3)
				{
					cv::cvtColor(srcWithRect, srcWithRect, CV_BGR2RGB);
					emit sendImage(srcWithRect);
					Sleep(30);
				}
				else
				{
					emit sendImage(srcWithRect);
				}
			}
			else
			{
				emit sendImage(imNonZeroNum);
			}
			//************* image processing end ************//
			
			if (ZeroNum > minPixNumber)
			{
				nRet = saveImage();
				if (nRet != MV_OK)
				{
					emit returnInfo("save image failed.");
					break;
				}
			}
			else
			{
				emit returnInfo("this picture is passed.");
			}
			if (g_bExit)
			{
				nRet = closeDevice();
				if (nRet != MV_OK)
				{
					emit returnInfo("close device failed.");
				}
				emit returnInfo("Camera disconnected.");
				break;
			}
		}
		else
		{
			qDebug() << "get one frame failed" << nRet;
			emit returnInfo("get one frame failed" + std::to_string(nRet));
			break;
		}
	}
	return;
}

void WorkThread::closeDeviceBtn()
{
	g_bExit = true;
}

void WorkThread::recv_startSlot()
{
	g_bExit = false;
}

void WorkThread::showSourceImg()
{
	showSrc = true;
}

void WorkThread::showDstImg()
{
	showSrc = false;
}

void WorkThread::getPara(int thresh, int lowLimit, float inExpoTime)
{
	if (thresh > 0 && thresh <= 255 && lowLimit > 0 && lowLimit < 10e8
		&& inExpoTime > 0 && inExpoTime < 10e8)
	{
		inputThresh = thresh;
		minPixNumber = lowLimit;
		inExposureTime = inExpoTime;
		emit returnInfo("Parameter updated");
	}
	else
	{
		inputThresh = 30;
		minPixNumber = 500000;
		inExposureTime = 2000;
		emit returnInfo("Input invalid, please try again.");
	}
}

int WorkThread::SetExposureTime(double m_dExposureEdit)
{
	// ch:调节这两个曝光模式，才能让曝光时间生效
	// en:Adjust these two exposure mode to allow exposure time effective
	int nRet = m_pcMyCamera->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	nRet = m_pcMyCamera->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);

	nRet = m_pcMyCamera->SetFloatValue("ExposureTime", m_dExposureEdit);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	return MV_OK;
}

int WorkThread::saveImage(void)
{
	//nImageNum--;
	// ch:仅在第一次保存图像时申请缓存，在 CloseDevice 时释放
	// en:Request buffer only when save image for first time, release after CloseDevice
	if (NULL == m_pBufForSaveImage)
	{
		// ch:BMP图片大小：width * height * 3 + 2048(预留BMP头大小)
		// en:// BMP image size: width * height * 3 + 2048 (Reserved BMP header size)
		m_nBufSizeForSaveImage = stImageInfo.nWidth * stImageInfo.nHeight * 3 + 2048;

		m_pBufForSaveImage = (unsigned char*)malloc(m_nBufSizeForSaveImage);
		if (NULL == m_pBufForSaveImage)
		{
			qDebug() << "NULL == m_pBufForSaveImage";
			emit returnInfo("NULL == m_pBufForSaveImage");
			return STATUS_ERROR;
		}
	}
	// ch:设置对应的相机参数 | en:Set camera parameter
	MV_SAVE_IMAGE_PARAM_EX stParam = { 0 };
	stParam.enImageType = m_nSaveImageType; // ch:需要保存的图像类型 | en:Image format to save
	stParam.enPixelType = stImageInfo.enPixelType;  // ch:相机对应的像素格式 | en:Camera pixel type
	stParam.nWidth = stImageInfo.nWidth;         // ch:相机对应的宽 | en:Width
	stParam.nHeight = stImageInfo.nHeight;          // ch:相机对应的高 | en:Height
	stParam.nDataLen = stImageInfo.nFrameLen;
	stParam.pData = m_pBufForDriver;
	stParam.pImageBuffer = m_pBufForSaveImage;
	stParam.nBufferSize = m_nBufSizeForSaveImage;  // ch:存储节点的大小 | en:Buffer node size
	stParam.nJpgQuality = 80;       // ch:jpg编码，仅在保存Jpg图像时有效。保存BMP时SDK内忽略该参数
									// en:jpg encoding, only valid when saving as Jpg. SDK ignore this parameter when saving as BMP

	int	nRet = m_pcMyCamera->SaveImage(&stParam);
	if (MV_OK != nRet)
	{
		qDebug() << "saveimage failed;";
		emit returnInfo("saveimage failed;");
		return STATUS_ERROR;
	}
	else
	{
		qDebug() << "saveimage done;";
		emit returnInfo("saveimage done;");
	}

	char chImageName[64] = { 0 };
	if (MV_Image_Bmp == stParam.enImageType)
	{
		sprintf_s(chImageName, IMAGE_NAME_LEN, "Image_w%d_h%d_fn%03d.bmp", stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
	}
	else if (MV_Image_Jpeg == stParam.enImageType)
	{
		sprintf_s(chImageName, IMAGE_NAME_LEN, "Image_w%d_h%d_fn%03d.jpg", stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
	}

	FILE* fp = fopen(chImageName, "wb");
	if (NULL == fp)
	{
		qDebug() << "write image failed, maybe you have no privilege";
		emit returnInfo("write image failed, maybe you have no privilege");
		return STATUS_ERROR;
	}
	else
	{
		qDebug() << "file opened";
		emit returnInfo("file opened");
	}

	std::string path = chImageName;
	std::string msg = "\"path\":\"H:\\test\\VS2015_projects\\ImageGrabing\\ImageGrabing\\" + path + "\",\"terminal\":\"M8\",\"type\":\"0824\"";
	std::string msg1 = "\"path\":\"D:\\MyData\\Desktop\\4.jpg\",\"terminal\":\"007\",\"type\":\"9427\"";
	std::cout << msg;
	//emit returnInfo(msg);
	fwrite(m_pBufForSaveImage, 1, stParam.nImageLen, fp);
	fclose(fp);
	SendMsg(msg);
	return MV_OK;
}
