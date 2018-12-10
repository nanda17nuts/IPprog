#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
	int x=10,y=10,z=10,sx[3][3]={-1,0,1,-2,0,2,-1,0,1},sy[3][3]={-1,-2,-1,0,0,0,1,2,1},a=0,b=0,p,q,d; float c=0; namedWindow("IMG",WINDOW_NORMAL);
	createTrackbar("slider1","IMG",&x,100); 
	createTrackbar("slider2","IMG",&y,100); 
	createTrackbar("slider3","IMG",&z,100);
	Mat img=imread("fruits.png",0);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j,k=0,l=0,m,n;
	while(1){
	for(i=1;i<img.rows-1;i++)
		for(j=1;j<img.cols-1;j++)
		{
		  for(m=i-1,p=0;m<=i+1;m++,p++)
			for(n=j-1,q=0;n<=j+1;n++,q++)
				a=a+ (img.at<uchar>(m,n))*(sx[p][q]); 
		  for(m=i-1,p=0;m<=i+1;m++,p++)
			for(n=j-1,q=0;n<=j+1;n++,q++)
				b=b+ (img.at<uchar>(m,n))*(sy[p][q]);
		  c=sqrt((a*a)+(b*b));
		  if(a>x || b>y || c>z ) img1.at<uchar>(i,j)=0;
		  else img1.at<uchar>(i,j)=255;

		a=0;b=0;c=0;
		
				 
		}
	


	
	imshow("IMG",img1);
	waitKey(1);
	}
	waitKey(0);

}
