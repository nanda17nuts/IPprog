#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("fruits.png",1);
	Mat img1=img.clone();
	namedWindow("IMG",WINDOW_NORMAL);
	int i,j,r1=0,r2=0,b1=0,b2=0,g1=0,g2=0;
	createTrackbar("slider1","IMG", &b1,254);
	createTrackbar("slider2","IMG", &b2,254);
	createTrackbar("slider3","IMG", &g1,254);
	createTrackbar("slider4","IMG", &g2,254);
	createTrackbar("slider5","IMG", &r1,254);
	createTrackbar("slider6","IMG", &r2,254);
	while(1){
	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
	{ if((img.at<Vec3b>(i,j)[0]>b1) && (img.at<Vec3b>(i,j)[0]<b2) && (img.at<Vec3b>(i,j)[1]>g1) && (img.at<Vec3b>(i,j)[1]<g2) && (img.at<Vec3b>(i,j)[2]>r1) && (img.at<Vec3b>(i,j)[2]<r2))
		{
			img1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			img1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
			img1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
			
		 }
	   else
		{ img1.at<Vec3b>(i,j)={0,0,0};}
	}
	imshow("IMG",img1);
	waitKey(1);
	}
	waitKey(0);
}
