//#include "stdafx.h"
#include "Solution.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;

Solution::Solution()
{
}

Solution::~Solution()
{
}

//计算面积
int Solution::calNonZero(cv::Mat src, cv::Mat& dst, int thresholdValue)
{
	cv::Mat threImg, blurImg;
	norThresh(src, threImg, thresholdValue);
	cv::medianBlur(threImg, blurImg,3);
	blurImg.copyTo(dst);
	return countNonZero(blurImg);
	
#if 0
	namedWindow("blurImg", WINDOW_NORMAL);
	imshow("blurImg", blurImg);
	waitKey();
#endif
}

//输入为 二值化原图，原图，保存ROI的Mat
void Solution::findRect(cv::Mat srcBw, cv::Mat &srcAddRect, cv::Mat& imRoi)
{
	//找到轮廓的最小包围边框，并画出包围矩形
	//输入为二值图
	cv::Mat src_copy; cv::Mat temp1;
	srcAddRect.copyTo(src_copy);
	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> hierarchy;
	findContours(srcBw, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	vector<cv::Rect> boundRect(contours.size());  //定义一个矩形类集合

	for (int i = 0; i < contours.size(); i++)
	{
		//drawContours(imageROI, contours, i, Scalar(0,0,255), 1, 8); //画出轮廓
		boundRect[i] = cv::boundingRect(cv::Mat(contours[i]));

		//删除过小的矩形
		//if (boundRect[i].width >(srcBw.cols - 100) || boundRect[i].height < 10 || boundRect[i].area() < 20)
		if (boundRect[i].width >(srcBw.cols - 100) || boundRect[i].height < 0.3*srcBw.cols ||
			boundRect[i].width < 0.2*srcBw.rows || boundRect[i].area() < 1000)
			continue;

		//删除宽高比过小的矩形
		double proportion = boundRect[i].width / boundRect[i].height;
		if (proportion > 3)
			continue;
		//截取ROI区域，并返回ROI图片
		imRoi = src_copy(cv::Rect(boundRect[i].tl().x, boundRect[i].tl().y,
			boundRect[i].width, boundRect[i].height));

		//画出矩形包围框，rect.tl(),为矩形类左上点坐标，rect.br()为左下点的坐标
		//drawContours(dst, contours, i, Scalar(0, 0, 255), -1, 8); //画出轮廓
		rectangle(srcAddRect, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(255, 0, 0), 1, 8, 0);
		//temp1.copyTo(dst);
	}

#if 0
	namedWindow("rect_display", WINDOW_NORMAL);
	imshow("rect_display", dst);
#endif
	}

void Solution::norThresh(const cv::Mat src, cv::Mat& dst, const int thresh)
{
	if (src.channels() == 3)
	{
		cv::Mat srcGray;
		cv::cvtColor(src, srcGray, cv::COLOR_BGR2GRAY);
		cv::threshold(srcGray, dst, thresh, 255, cv::THRESH_BINARY);
	}
	else
	{
		cv::threshold(src, dst, thresh, 255, cv::THRESH_BINARY);
	}
}		

void Solution::adThreshhold(cv::Mat& src, cv::Mat& dst)
{
	int maxVal = 255;
	int blockSize = 41;
	double c = 0;
	if (src.channels() == 3)
		cvtColor(src,src, cv::COLOR_BGR2GRAY);
	cv::adaptiveThreshold(src, dst, maxVal, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, blockSize, c);
}

void Solution::figShow(std::string winName, const cv::Mat figure)
{
	cv::namedWindow(winName, CV_WINDOW_NORMAL);
	cv::imshow(winName, figure);
	cv::waitKey(20);
}
