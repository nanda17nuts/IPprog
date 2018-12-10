#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("lena.png",0);
	int i,j;
	int a[256];
	for(i=0;i<256;i++) a[i]=0;
	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		{ a[img.at<uchar>(i,j)]++;}

	int max=a[0];
	for(i=0;i<256;i++)
		if(a[i]>max) max=a[i];

	Mat comb(max,256,CV_8UC1,Scalar(0));
	for(j=0;j<256;j++)
	for(i=0;i<(max-a[j]);i++)
		comb.at<uchar>(i,j)=255;
	
	namedWindow("IMG",WINDOW_NORMAL);
	imshow("IMG",comb);
	waitKey(10000);
}
