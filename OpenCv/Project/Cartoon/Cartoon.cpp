#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat img = imread(path);
	if (img.empty())
	{
		cout << "read img error" << endl;
		return -1;
	}
	imshow(path, img);

	Mat imgMedian;
	medianBlur(img, imgMedian, 7);

	Mat imgCanny;
	Canny(imgMedian, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(2,2));
	dilate(imgCanny, imgCanny, kernel);

	imgCanny = imgCanny / 255;
	imgCanny = 1 - imgCanny;

	Mat imgCannyf;
	imgCanny.convertTo(imgCannyf, CV_32FC3);

	blur(imgCannyf, imgCannyf, Size(5, 5));
	
	Mat imgBF;
	bilateralFilter(img, imgBF, 9, 150.0, 150.0);

	Mat result = imgBF / 25;
	result = result * 25;

	Mat imgCanny3c;
	Mat cannyChannels[] = { imgCannyf, imgCannyf, imgCannyf };
	merge(cannyChannels, 3, imgCanny3c);

	Mat resultf;
	result.convertTo(resultf, CV_32FC3);

	multiply(resultf, imgCanny3c, resultf);

	resultf.convertTo(result, CV_8UC3);
	imshow("Result", result);
	

	waitKey(0);
	return 0;
}
