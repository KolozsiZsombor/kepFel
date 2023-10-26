#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int bah() {
	Mat img = imread("edges_noise.png", IMREAD_GRAYSCALE);
	GaussianBlur(img, img, Size(5, 5),1.0);
	//medianBlur(img, img, 3);
	Mat_<uchar> im = (Mat_<uchar>)img;
	Mat g = Mat::zeros(img.size(), CV_8U); // 32 -> int ; 165 -> short
	for (int y = 0; y < img.rows; ++y) {
		for (int x = 0; x < img.cols; ++x) {
			g.at<uchar>(y, x) = 
				fabs(im(y, x) - im(y + 1, x + 1)) + fabs(im(y + 1, x) - im(y, x + 1));
		}
	}

	Mat g2;
	threshold(g, g2, 30, 255, THRESH_BINARY);

	imshow("eredeti", img);
	imshow("roberts", g);
	imshow("roberts_edges", g2);
	waitKey();


	return 0;
}