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
	int x=2;
	namedWindow("IMG",WINDOW_NORMAL);
	createTrackbar("slider","IMG",&x,10);
	Mat img=imread("veg.jpg",0);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j,a,b[100],k=0,l=0,m,n;
	while(1){
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
		 
		
			for(m=i-x/2;m<=i+x/2;m++)
				for(n=j-x/2;n<=j+x/2;n++)
				{
					a=IsValid(m,n,img.rows,img.cols);
					if(a==1) b[k++]=img.at<uchar>(m,n);
				
				}
		
			
			int s;
			for(m=0;m<k;m++)
				for(n=m;n<k;n++)
				{			
					if(b[n]<=b[m]) 
					{
						s=b[n];
						b[n]=b[m]; 
						b[m]=s;
					}

			        }
				img1.at<uchar>(i,j)=b[k/2];
				k=0;
				 
		}
	

	
	imshow("IMG",img1);
	waitKey(0);
	}
	waitKey(10000);
}

