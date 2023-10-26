#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int ot() {
	Mat img = imread("kurama.jpg", IMREAD_COLOR);

	Mat dest = Scalar(255,255,255) - img;
	imshow("ablak", img);
	imshow("ablak2", dest);
	waitKey();

	return 0;

}