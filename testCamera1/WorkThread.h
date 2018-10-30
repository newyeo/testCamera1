#pragma once

#include <QtCore/qthread.h>
#include <QtCore/qdebug.h>
#include "MvCameraControl.h"
#include "MyCamera.h"
#include <opencv2/opencv.hpp>
#include <QtCore/qobject.h>
#include "Solution.h"
#pragma execution_character_set("utf-8")

#define STATUS_ERROR -1

class WorkThread : public QThread
{
	Q_OBJECT

public:
	WorkThread();
	~WorkThread();
	void findRect(cv::Mat &src, cv::Mat &dst);

protected:
	void run();

private:
	MV_CC_DEVICE_INFO_LIST  m_stDevList;
	MV_SAVE_IAMGE_TYPE      m_nSaveImageType = MV_Image_Jpeg;
//	MV_FRAME_OUT_INFO_EX    stImageInfo = { 0 };
	MV_FRAME_OUT_INFO_EX    stImageInfo;

//  HWND  m_hwndDisplay;
	bool m_bOpenDevice = false;
	bool m_bStartGrabbing = false;
	bool g_bExit = false;
	bool showSrc = true;
	const int TRUE = 1;
	const int FALSE = 0;
//	const int STATUS_ERROR = -1;
	const int IMAGE_NAME_LEN = 64;
	int       minPixNumber;
	int		  inputThresh;
	float     inExposureTime;

	unsigned char*  m_pBufForSaveImage = NULL;
	unsigned int    m_nBufSizeForSaveImage = 0;
	unsigned char*  m_pBufForDriver = NULL;
	unsigned int    m_nBufSizeForDriver;
	unsigned int    nValue = PixelType_Gvsp_RGB8_Packed;  //PixelType_Gvsp_RGB8_Packed »ò PixelType_Gvsp_Mono8

	CMyCamera*      m_pcMyCamera;
	Solution        solu;
	int             openDevice(void);
	int             closeDevice(void);
	int             saveImage(void);
	int             SetExposureTime(double m_dExposureEdit);

signals:
	void  sendImage(cv::Mat image);
signals:
	void  returnInfo(std::string info);
signals:
	void  returnRes(std::string res);

public slots:
	void closeDeviceBtn();
	void showSourceImg();
	void showDstImg();
	void getPara(int, int, float);
	void recv_startSlot();
};

