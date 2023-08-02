#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path, IMREAD_GRAYSCALE);
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path,  src);

	Mat dst;
	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("dst", dst);

	waitKey(0);
    return 0;
}
