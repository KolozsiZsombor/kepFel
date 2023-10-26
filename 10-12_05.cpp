#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int n() {
	Mat dest;
	Mat img = imread("edges_noise.png", IMREAD_GRAYSCALE);
	GaussianBlur(img, img, Size(5, 5), 1.0);
	Canny(img, dest, 60, 120);
	convertScaleAbs(dest, dest);

	imshow("img", img);
	imshow("dest", dest);
	waitKey();
	return 0;
}