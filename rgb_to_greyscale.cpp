#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("fruits.png",1),a(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j;
	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
	{ a.at<uchar>(i,j)= (0.114*img.at<Vec3b>(i,j)[0])+(0.587*img.at<Vec3b>(i,j)[1])+(0.299*img.at<Vec3b>(i,j)[2]); }
	namedWindow("IMG",WINDOW_NORMAL);
	imshow("IMG",a);
	waitKey(10000);
}
