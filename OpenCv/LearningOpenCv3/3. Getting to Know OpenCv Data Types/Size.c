#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat frame = imread(path);
	if (frame.empty()) 
	{
		cout << "read img error" << endl;
		return -1;
	}

	Size2i s1;
	s1.width  = frame.cols;
	s1.height = frame.rows;
	cout << s1 << endl;

	system("pause");
	return 0;
}
