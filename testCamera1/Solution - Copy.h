#pragma once
#include <opencv2/opencv.hpp>

class Solution
{
public:
	Solution();
	~Solution();
	int calNonZero(cv::Mat src, cv::Mat& dst, int thresholdValue = 30);
	void adThreshhold(cv::Mat& src,cv::Mat& dst);
	void norThresh(const cv::Mat src, cv::Mat& dst, const int thresh = 200);
	void findRect(cv::Mat srcBw, cv::Mat &srcAddRect, cv::Mat& imRoi);
	void figShow(const std::string winName, const cv::Mat figure);
};

