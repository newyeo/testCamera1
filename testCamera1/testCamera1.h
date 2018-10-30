#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testCamera1.h"
#include "WorkThread.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <string>

class testCamera1 : public QMainWindow
{
	Q_OBJECT

public:
	testCamera1(QWidget *parent = Q_NULLPTR);

private:
	Ui::testCamera1Class ui;
	WorkThread  *workThread;

private slots:
	void slotStart();
	void slotStop();
	void showSrcImage(cv::Mat img);
	void showInfo(std::string info);
	void showResult(std::string res);
	void showSrcBtn();
	void showDstBtn();
	void getParaBtn();
	void getTotalPixBtn();

signals:
	void sendCloseSignal();
signals:
	void shwoSrcSigal();
signals:
	void shwoDstSigal();
signals:
	void sendPara(int, int, float);
signals:
	void sendStartSignal();
};
