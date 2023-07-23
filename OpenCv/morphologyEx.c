#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
void cv::erode(
	cv::InputArray		src,								// Input image
	cv::0utputArray		dst,								// Result image
	int					op,									// Operator(e.g. MORPH_OPEN)
	cv::InputArray		element,							// Structuring, a cv::Mat()
	cv::Point			anchor		= cv::Point(-1,-1),		// Location of anchor point
	int					iterations	= 1��					// Number of times to apply
	int					borderType	= cv::BORDER CONSTANT	// Border extrapolation
	const cv::Scalar&	borderValue = cv::morphologyDefaultBorderValue()
);

MORPH_OPEN			���������ȸ�ʴ�����ͣ����ο���������ʴ��ʴ�������ͣ�
MORPH_CLOSE			�ղ������������ٸ�ʴ
MORPH_TOPHAT		��ñ������TopHat(src) = src - open(src)		//Isolate brighter���õ��˱�Դͼ������Ļ��Ʋ���
MORPH_BLACKHAT		��ñ������BlackHat(src) = close(src) - src	//Isolate dimmer �� �õ��˱�Դͼ������Ļ��Ʋ���
MORPH_GRADIENT		��̬ѧ�ݶȣ�gradient(src) = dilate(src) - erode(src)
*/

int main()
{
	string path = "C:\\Users\\Administrator\\Desktop\\OpenCv\\Lenna.jpg";
	Mat src = imread(path), src_bin, dst;
	if (src.empty())
	{
		cout << "can not load " << path << endl;
		return -1;
	}

	Laplacian(src, src_bin, CV_8U, 3, 1, 0, BORDER_DEFAULT);
	imshow(path, src_bin);

	morphologyEx(src_bin, dst, MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst1", dst);

	morphologyEx(src_bin, dst, MORPH_CLOSE, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst2", dst);

	morphologyEx(src_bin, dst, MORPH_TOPHAT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst3", dst);

	morphologyEx(src_bin, dst, MORPH_BLACKHAT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst4", dst);

	morphologyEx(src_bin, dst, MORPH_GRADIENT, cv::Mat(), cv::Point(-1, -1), 1, BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
	imshow("dst5", dst);

	waitKey(0);
	return 0;
}