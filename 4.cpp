#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int negy() {
	Mat img = imread("karuma.jpg", IMREAD_COLOR);
	Rect r(20, 20, img.cols - 40, img.rows - 40);
	imwrite("kurama_kicsi.png", img(r));
	imshow("ablak", img);
	waitKey();

	return 0;
}