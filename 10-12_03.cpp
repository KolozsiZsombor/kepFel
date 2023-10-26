#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int dadas() {

	Mat img = imread("edges_noise.png", IMREAD_GRAYSCALE);

	Mat dx, dy,g,g2;
	Sobel(img, dx, CV_16S, 1, 0);
	Sobel(img, dy, CV_16S, 0, 1);
	//cv::sqrt(dx.mul(dx) + dy.mul(dy) + dx,g);
	g = cv::abs(dx) + cv::abs(dy);
	
	convertScaleAbs(g,g,1.0);

	imshow("img", img);
	imshow("grad", g);
	waitKey();
	return 0;
}