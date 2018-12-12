#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <queue>
using namespace cv;
using namespace std;
struct mpoint
	{
	int x,y,m,n;
	};
int main(){
	Mat img=imread("Binary1.png",0);
	Mat d(img.rows,img.cols,CV_8UC1,Scalar(255));
	namedWindow("IMG",WINDOW_NORMAL);
	
	queue<mpoint> q;
	
	struct mpoint u,v;
	cout<<"here"<<endl;
	vector<vector<struct mpoint> > z(img.rows,vector<struct mpoint>(img.cols));
	int i=0,j=0,k,l;
	z[0][0].x=0; z[0][0].y=0; z[0][0].m=1; z[0][0].n=0;
	q.push(z[0][0]);

	while(!q.empty())
	{
		u=q.front();
		i=u.x; j=u.y;
		for(k=i-1;k<=i+1;k++)
		{
			for(l=j-1;l<=j+1;l++)
			{
				if(k>=0 && k<img.rows && l>=0 && l<img.cols && (z[k][l].m!=1) && (z[k][l].n!=1) && (k != i && l != j))
				{
					v.x=k; v.y=l;  v.m=1; v.n=0; q.push(v);
					z[k][l].m=1;
					z[k][l].n=0;
				}
			}
		}
		// cout << "Hey!\n";
		z[i][j].n=1;
		d.at<uchar>(i,j)=0;
		q.pop();		
		imshow("IMG",d);
		waitKey(1);

	}
	imshow("IMG",d);
	waitKey(0);

}