#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int egy() {
	Mat img = imread("background.jpg",IMREAD_UNCHANGED);
	if (img.empty()) {
		cout << "Nincs kep!" << endl;
		return -1;
	}
	int t = img.type();
	if (t == CV_8UC1) {
		cout << "Szurkeskalas 8-bit es" << endl;

	}

	else if (t == CV_8UC3) {
		cout << "Szines kep" << endl;
	}

	else {
		cout << "Egyeb" << endl;
	}
	imshow("window", img);
	waitKey();

	return 0;
}