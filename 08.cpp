#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int nyolc() {
	Mat fg = imread("orange1.jpg", IMREAD_COLOR);
	Mat bg = Mat::zeros(fg.size(), fg.type());
	Vec3b c, hsv;
	Mat hsv_fg;
	cvtColor(fg, hsv_fg, COLOR_BGR2HSV);
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			hsv = hsv_fg.at<Vec3b>(i, j);
			if (hsv[0] < 30) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}

	imshow("ablak", bg);
	waitKey();

	return 0;
}