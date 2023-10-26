#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void convertLab(const Mat rgb, Mat& lab) {
	Mat rgbf;
	rgb.convertTo(rgbf, CV_32FC3, 1 / 255.0);
	cvtColor(rgbf, lab, COLOR_BGR2Lab);
}

double difference(const Mat lab1, const Mat lab2) {
	Mat diff = lab1 - lab2;
	Mat diff2 = diff.mul(diff);
	vector<Mat> chs;
	split(diff, chs);
	Mat e;
	sqrt(chs[0] + chs[1] + chs[2],e);
	return mean(e)[0];
}

int tiz() {
	Mat fg1 = imread("padlolapok/etalon.png", IMREAD_COLOR);
	Mat elab;
	convertLab(fg1, elab);

	Mat fg2 = imread("padlolapok/fa_5.png", IMREAD_COLOR);
	Mat ilab;
	convertLab(fg2, ilab);

	cout << difference(fg1, fg2) << endl;

	



	//imshow("window", fg);
	//waitKey(0);

	return 0;
}