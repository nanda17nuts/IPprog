#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("fruits.png",1),comb(img.rows,img.cols*2,CV_8UC3,Scalar(0,0,0));
	int i,j;
	

	for(i=0;i<img.rows;i++)
	for(j=img.cols;j<img.cols*2;j++)
		{comb.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);}

	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		{comb.at<Vec3b>(i,j)=img.at<Vec3b>(i,img.cols-1-j);}
	namedWindow("IMG",WINDOW_NORMAL);
	imshow("IMG",comb);
	waitKey(10000);
}
