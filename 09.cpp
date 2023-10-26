#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int kilenc() {
	Mat fg = imread("orange1.jpg", IMREAD_COLOR);
	Mat bg = Mat::zeros(fg.size(), fg.type());
	Mat hsv_fg;
	cvtColor(fg, hsv_fg, COLOR_BGR2HSV);
	Mat mask;
	inRange(hsv_fg, Scalar(0, 0, 0), Scalar(30, 255, 255), mask);
	fg.copyTo(bg, mask);

	imshow("ablak", bg);
	imshow("mask", mask);
	waitKey(0);


	return 0;
}