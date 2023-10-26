#include <iostream>
#include <core.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
    /* MORPHOLOGY
    Mat img = imread("galaxy.jpg", IMREAD_GRAYSCALE);
    Mat dest;
    morphologyEx(img,dest,MORPH_TOPHAT,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));

    imshow("img",img);
    imshow("dest",dest);
    waitKey(0);
    return 0;
    */
    /* ERODE
    Mat img = imread("dog.jpg",IMREAD_GRAYSCALE);
    resize(img,img,Size(img.cols / 2, img.rows/ 2));

    Mat bin, bin2, bin3;
    threshold(img,bin,120,255, THRESH_BINARY);

    erode(img,bin2,getStructuringElement(MORPH_ELLIPSE,Size(15,15)));

    imshow("img",img);
    imshow("erode",bin2);

    waitKey();
    */
    /* KONTUR
    Mat img = imread("sajt_keskeny_keret.png",IMREAD_GRAYSCALE);
    Mat bin,bin2,bin3,fr;

    threshold(img,bin,250,255,THRESH_BINARY_INV);
    medianBlur(bin,bin,3);

    copyMakeBorder(bin,fr,40,40,40,40, BORDER_CONSTANT,0);

    dilate(bin,bin2,getStructuringElement(MORPH_ELLIPSE,Size(59,59)));
    erode(bin2,bin3,getStructuringElement(MORPH_ELLIPSE,Size(59,59)));
    Mat dest = bin3(Rect(40, 40, bin.cols, bin.rows));

    imshow("img",img);
    imshow("dilate",bin2);
    imshow("erode",bin3);
    imshow("dest", dest);
    waitKey();
    */
    /* SZITAKOTO
    Mat bin,bin2,bin3;
    Mat img = imread("szitakoto.jpg",IMREAD_GRAYSCALE);
    threshold(img,bin,120,255,THRESH_BINARY_INV);
    erode(bin,bin2,getStructuringElement(MORPH_ELLIPSE,Size(3,9)));
    dilate(bin2,bin3,getStructuringElement(MORPH_ELLIPSE,Size(3,9)));

    Mat part = bin3(Rect(bin.cols / 3,0,bin.cols - bin.cols/3,bin.rows));


    imshow("img",img);
    imshow("mask",bin);
    imshow("erode",bin2);
    imshow("dilate(vissza)", bin3);
    imshow("part", part);
    waitKey();
    */
   /* ANNOTALTSEJT*/

   Mat img = imread("annotalt_sejt.png",IMREAD_COLOR);
   vector<Mat> chs;
   split(img,chs); // chs[2]
   Mat bin,bin2,bin3,fr;
   threshold(chs[2],bin,230,255,THRESH_BINARY);

   morphologyEx(bin, bin2, MORPH_HITMISS, getStructuringElement(MORPH_CROSS, Size(3, 3)));

    vector<Point> pts;

   for (int i = 0; i < bin2.rows; ++i) {
        for (int j = 0; j < bin2.cols; ++j) {
            if (bin2.at<uchar>(i,j)>0){
                pts.push_back(Point(j,i));
            }
        }
   }

   for (auto p:pts)
   {
    drawMarker(img,p,Scalar(0,255,0),MARKER_DIAMOND,5,3);
   }


   imshow("img",img);
   imshow("mask",bin);
   waitKey();
   return 0;
}