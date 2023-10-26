#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int hat() {
	Mat fg = imread("kurama.jpg", IMREAD_COLOR);
	Mat bg = imread("background.jpg", IMREAD_COLOR);
	Mat bg2;
	resize(bg, bg2, fg.size());
	Vec3b c;
	Vec3b white(255, 255, 255);

	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
				if (c[0] < 215) {
					bg2.at<Vec3b>(i, j) = c;
				}
		}
	}

	imshow("ablak", bg2);
	waitKey();

	return 0;

}