#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat img=imread("fruits.png",1);
	int i,j,b;
	int a[256];
	for(i=0;i<256;i++) a[i]=0;
	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		{ b=img.at<Vec3b>(i,j)[0];
			a[b]++;}
	int max1=a[0];
	for(i=0;i<256;i++)
		if(a[i]>max1) max1=a[i];
cout<<max1<<endl;

	Mat comb(max1,256,CV_8UC1,Scalar(0));
	for(j=0;j<256;j++)
	for(i=0;i<(max1-a[j]);i++)
		comb.at<uchar>(i,j)=255;
	
	namedWindow("IMG",WINDOW_AUTOSIZE);
cout<<"A"<<endl;
	imshow("IMG",comb);
cout<<"A"<<endl;
	waitKey(0);
cout<<"A"<<endl;
	

	
}
