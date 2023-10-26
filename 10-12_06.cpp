#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int u() {
	Mat img = imread("go2.png", IMREAD_COLOR);
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	vector<Vec3f> circles;
	cv::HoughCircles(gray, circles, HOUGH_GRADIENT_ALT, 2, 10, 80, 50, 24, 28);

	for (Vec3f c : circles) {
		if ((gray.at<uchar>(c[1], c[0])) > 160){
			circle(img, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3);
		}
		else {
			circle(img, Point(c[0], c[1]), c[2], Scalar(0, 255, 0), 3);
		}
	}

	imshow("img", img);

	waitKey();
	return 0;
}