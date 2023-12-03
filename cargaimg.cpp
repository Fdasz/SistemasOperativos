#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(){

Mat image = imread("imagen_a_color.jpg", IMREAD_COLOR);

for (int r=0; r<image.rows; r++){
	for (int c=0; c<image.cols; c++){
		Point3_<uchar>* p = image.ptr<Point3_<uchar> > (r, c);
		printf(" (%d %d %d) " , p->x, p->y, p->z);
	}
}
return 0;
}
