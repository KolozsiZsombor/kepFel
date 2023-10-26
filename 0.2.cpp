#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int ketto() {
	Mat img = imread("background.jpg", IMREAD_UNCHANGED);
	Mat mask(img.size(), CV_8UC1);
	Mat img2 = img.clone();
	img2.setTo(Scalar(0, 0, 255));


	imshow("ablak", img);
	imshow("ablak2", img2);
	waitKey();

	return 0;
}