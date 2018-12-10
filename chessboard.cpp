#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat a(320,320,CV_8UC3,Scalar(0,0,0));
	int i,j;
	for(i=0;i<320;i++)
		for(j=0;j<320;j++)
		{if(((j/40)%2==1 && (i/40)%2==1) || ((j/40)%2==0 && (i/40)%2==0))
 {a.at<Vec3b>(i,j)={255,255,255};}}
	int x=a.at<Vec3b>(2,5)[1];
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(10000);
}
