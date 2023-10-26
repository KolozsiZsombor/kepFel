#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int bn() {
	Mat img = imread("KossuthSquare\SnapShot-20180731_173715.jpg");
	Mat acc = Mat::zeros(img.size(), CV_64FC3);
	int nFrames = 0;

	for (int i = 715; i < 918; ++i) {
		img = imread("SnapShot-20180731_173" + to_string(i) + ".jpg");
		if (img.empty()) {
			imshow("ter", img);
			waitKey(33);
			accumulate(img, acc);
			nFrames++;
		}
	}

	Mat dest;
	acc.convertTo(dest, CV_8UC3, 1.0 / nFrames);
	imshow("Zajszurt", dest);
	waitKey();


	return 0;
}