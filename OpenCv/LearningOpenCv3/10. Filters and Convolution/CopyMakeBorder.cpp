#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/*
	在图像处理过程中，因为卷积算子有一定大小，所以就会导致源图像一定范围的边界不能被处理，这时就需要将边界进行适当扩充。
	copyMakeBorder 将源图像复制到目标图像的中间并在图像周围形成边框。

	void cv::copyMakeBorder(
		cv::InputArray src, 	// Input image
		cv::OutputArray dst, 	// Result image
		int top, 		// Top side padding (pixels)
		int bottom, 		// Bottom side padding (pixels)
		int left, 		// Left side padding (pixels)
		int right, 		// Right side padding (pixels)
		int borderType, 	// Pixel extrapolation method
		const cv::Scalar& value = cv::Scalar() // Used for constant borders
	);

	Border type Effect
	cv::BORDER_CONSTANT	复制指定的常量扩展边界
	cv::BORDER_WRAP		复制对边的像素扩展边界
	cv::BORDER_REPLICATE	复制边缘的像素扩展边界
	cv::BORDER_REFLECT	通过镜像复制扩展边界
	cv::BORDER_REFLECT_101	通过镜像复制扩展边界，边界像素除外
	cv::BORDER_DEFAULT	cv::BORDER_REFLECT_101的别名
*/

int main()
{
	string path = "C:\\Users\\xuxide\\Desktop\\opencv\\Lenna.jpg";
	Mat src = imread(path);

	Mat dst1, dst2, dst3, dst4, dst5, dst6;

	copyMakeBorder(src, dst1, 100, 100, 100, 100, BORDER_DEFAULT);
	copyMakeBorder(src, dst2, 100, 100, 100, 100, BORDER_CONSTANT);
	copyMakeBorder(src, dst3, 100, 100, 100, 100, BORDER_ISOLATED);
	copyMakeBorder(src, dst4, 100, 100, 100, 100, BORDER_REFLECT);
	copyMakeBorder(src, dst5, 100, 100, 100, 100, BORDER_REPLICATE);
	copyMakeBorder(src, dst6, 100, 100, 100, 100, BORDER_WRAP);

	imshow("BORDER_DEFAULT", dst1);
	imshow("BORDER_CONSTANT", dst2);
	imshow("BORDER_ISOLATED", dst3);
	imshow("BORDER_REFLECT", dst4);
	imshow("BORDER_REPLICATE", dst5);
	imshow("BORDER_WRAP", dst6);

	waitKey(0);
	return 0;
}
