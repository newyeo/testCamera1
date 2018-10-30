#include "testCamera1.h"
#include <opencv2/opencv.hpp>
#include <QtCore/qdatetime.h>
#include <windows.h>
#include "WorkThread.h"

testCamera1::testCamera1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<std::string>("std::string");
	workThread = new WorkThread();
	QObject::connect(workThread, SIGNAL(sendImage(cv::Mat)), this, SLOT(showSrcImage(cv::Mat)));
	QObject::connect(this, SIGNAL(sendCloseSignal()), workThread, SLOT(closeDeviceBtn()));
	QObject::connect(workThread, SIGNAL(returnInfo(std::string)), this, SLOT(showInfo(std::string)));
	QObject::connect(workThread, SIGNAL(returnRes(std::string)), this, SLOT(showResult(std::string)));
	QObject::connect(this, SIGNAL(shwoSrcSigal()), workThread, SLOT(showSourceImg()));
	QObject::connect(this, SIGNAL(shwoDstSigal()), workThread, SLOT(showDstImg()));
	QObject::connect(this, SIGNAL(sendPara(int, int, float)), workThread, SLOT(getPara(int, int, float)));
	QObject::connect(this, SIGNAL(sendStartSignal()), workThread, SLOT(recv_startSlot()));
}

void testCamera1::slotStart()
{
	qDebug() << "slotStart";
	showInfo("slotStart");
	emit sendStartSignal();
	workThread->start();
}

void testCamera1::slotStop()
{
	emit sendCloseSignal();
}

void testCamera1::showInfo(std::string info)
{
	QDateTime currentDateTime = QDateTime::currentDateTime();
	QString currentDateTimeString = currentDateTime.toString("hh:mm:ss");
	QString infoStr = currentDateTimeString + " " + QString::fromStdString(info);
	ui.textEdit_display->append(infoStr);
}

void testCamera1::showResult(std::string res)
{
	ui.totalPxEdit->setText(QString::fromStdString(res));
}

void testCamera1::showSrcImage(cv::Mat img)
{
	cv::Mat mat = img;
	cv::Mat Rgb;
	QImage Img;
	if (mat.channels() == 3)//RGB Img
	{
		cv::cvtColor(mat, Rgb, CV_BGR2RGB);//ÑÕÉ«¿Õ¼ä×ª»»
		Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
	}
	ui.label->setPixmap(QPixmap::fromImage(Img).scaled(ui.label->size()));
	ui.label->resize(ui.label->pixmap()->size());
}

void testCamera1::showSrcBtn()
{
	emit shwoSrcSigal();
}

void testCamera1::showDstBtn()
{
	emit shwoDstSigal();
}

void testCamera1::getParaBtn()
{
	QString strthre = ui.threshEdit->text();
	QString strlowLimit = ui.lowLimitEdit->text();
	QString strExpoTime = ui.setExpoTimeEdit->text();

	int thre = strthre.toInt();
	int lowLimit = strlowLimit.toInt();
	float inExposureTime = strExpoTime.toInt();
	emit sendPara(thre, lowLimit, inExposureTime);
}

void testCamera1::getTotalPixBtn()
{

}
