#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int harom() {
	Mat img(400, 600, CV_8UC3);
	img.setTo(Scalar(0, 0, 255));

	Rect r(0,0,img.cols,img.rows/2);
	img(r).setTo(Scalar(0, 255, 255));

	imshow("ablak", img);
	waitKey();

	return 0;
}