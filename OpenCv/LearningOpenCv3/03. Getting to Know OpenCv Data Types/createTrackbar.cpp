#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int blurAmount = 15;
static void onChange(int pos, void* userInput);
static void onMouse(int event, int x, int y, int, void* userInput);


int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat lena = imread(path);
	if (lena.empty())
	{
		cout << "read img error" << endl;
		return -1;
	}

	namedWindow("Lena");
	createTrackbar("Lena", "Lena", &blurAmount, 30, onChange, &lena);
	setMouseCallback("Lena", onMouse, &lena);
	onChange(blurAmount, &lena);

	waitKey(0);
	return 0;
}

static void onChange(int pos, void* userData)
{
	if (pos <= 0) return;
	Mat imgBlur;
	Mat* img = (Mat*)userData;
	blur(*img, imgBlur, Size(pos, pos));
	imshow("Lena", imgBlur);
}

static void onMouse(int event, int x, int y, int, void* userInput)
{
	if (event != EVENT_LBUTTONDOWN)
	{ 
		return;
	}

	Mat* img = (Mat*)userInput;
	circle(*img, Point(x,y), 10, Scalar(0, 255, 0), 3);

	onChange(blurAmount, img);
}
