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

	vector<Mat> bgr;
	split(img, bgr);

	int numbins = 256;

	float range[] = { 0, 256 };
	const float* histRange = { range };

	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr[0], 1, 0, Mat(), b_hist, 1, &numbins, &histRange);
	calcHist(&bgr[1], 1, 0, Mat(), g_hist, 1, &numbins, &histRange);
	calcHist(&bgr[2], 1, 0, Mat(), r_hist, 1, &numbins, &histRange);

	int width = 512;
	int height = 300;
	Mat histImage(height, width, CV_8UC3, Scalar(20, 20, 20));

	normalize(b_hist, b_hist, 0, height, NORM_MINMAX);
	normalize(g_hist, g_hist, 0, height, NORM_MINMAX);
	normalize(r_hist, r_hist, 0, height, NORM_MINMAX);

	int binStep = cvRound((float)width / (float)numbins);
	for (int i = 1; i < numbins; i++)
	{
		line(histImage,
			Point(binStep * (i - 1), height - cvRound(b_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0)
		);
		line(histImage,
			Point(binStep * (i - 1), height - cvRound(g_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0)
		);
		line(histImage,
			Point(binStep * (i - 1), height - cvRound(r_hist.at<float>(i - 1))),
			Point(binStep * (i), height - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255)
		);
	}

	imshow("Histogram", histImage);

	waitKey(0);
	return 0;
}
