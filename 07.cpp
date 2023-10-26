#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int het() {
	Mat fg = imread("orange1.jpg", IMREAD_COLOR);
	Mat bg = Mat::zeros(fg.size(), fg.type());
	bg.setTo(Scalar(0, 255, 0));
	Mat mask;
	inRange(fg, Scalar(0, 0, 150), Scalar(150, 255, 255), mask);
	fg.copyTo(bg, mask);
	Vec3b c;
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c[2]>c[1] && c[2] > c[0]) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}

	

	imshow("ablak", bg);
	waitKey();

	return 0;
}