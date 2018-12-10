#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("fruits.png",1),img1(img.rows*2,img.cols*2,CV_8UC3,Scalar(0,0,0));
	int i,j;
	for(i=0;i<img.rows*2;i+=2)
	for(j=0;j<img.cols*2;j+=2)
		{
		img1.at<Vec3b>(i,j)=img.at<Vec3b>(i/2,j/2);
		img1.at<Vec3b>(i+1,j+1)=img.at<Vec3b>(i/2,j/2);
		img1.at<Vec3b>(i+1,j)=img.at<Vec3b>(i/2,j/2);
		img1.at<Vec3b>(i,j+1)=img.at<Vec3b>(i/2,j/2);
		}

	for(i=0;i<img.rows*2;i+=2)
	for(j=1;j<img.cols*2;j+=2)
		{img1.at<Vec3b>(i,j)=(img1.at<Vec3b>(i,j)+img1.at<Vec3b>(i+1,j)+img1.at<Vec3b>(i,j+1)+img1.at<Vec3b>(i+1,j+1))/4; }

	for(j=0;j<img.cols*2;j+=2)
	for(i=1;i<img.rows*2;i+=2)
		{img1.at<Vec3b>(i,j)=(img1.at<Vec3b>(i,j)+img1.at<Vec3b>(i+1,j)+img1.at<Vec3b>(i,j+1)+img1.at<Vec3b>(i+1,j+1))/4; }


	
	
	namedWindow("IMG",WINDOW_NORMAL);
	imshow("IMG",img1);
	waitKey(10000);
}
