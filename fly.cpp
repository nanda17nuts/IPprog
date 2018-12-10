#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int IsValid(int x, int y,int rows,int cols)
{
	if(x<0||y<0||x>=rows||y>=cols)
	return 0;
	return 1;
}
int main(){
	Mat img=imread("index.jpg",0);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j,a,b[9],k=0,l=0,m,n;
	for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		{
		 
		
			for(m=i-1;m<=i+1;m++)
			for(n=j-1;n<=j+1;n++)
				{
				a=IsValid(m,n,img.rows,img.cols);
				if(a==1) b[k++]=img.at<uchar>(m,n);
				//else b[k++]=256;
				}
		
			//for(k=0;k<9;k++)
			//if(b[k]<256) {l++;
				//img1.at<uchar>(i,j)+=b[k];}
			int xm=k, sum=0;
			while(xm--)
				sum+=b[xm];

		
		img1.at<uchar>(i,j)=sum/9;
		k=0; l=0;
			
		
		}
	

	namedWindow("IMG",WINDOW_NORMAL);
	imshow("IMG",img1);
	waitKey(10000);
}

