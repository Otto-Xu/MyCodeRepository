#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::buildPyramid(
	cv::InputArray		src,			// Input image
	cv::0utputArray		dst,			// Result image
	int			maxlevel		// Number of pyramid levels
)
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path), dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}
	imshow(path, src);

	pyrDown(src, dst, cv::Size());
	imshow("dst1", dst);

	std::vector<cv::Mat> gpyramid;
	buildPyramid(src, gpyramid, 3, BORDER_DEFAULT);
	imshow("dst2", gpyramid[0]);
	imshow("dst3", gpyramid[1]);
	imshow("dst4", gpyramid[2]);

	waitKey(0);
	return 0;
}
