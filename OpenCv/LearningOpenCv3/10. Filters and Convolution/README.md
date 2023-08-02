# 边界外推和边界处理
### 概述
图像在卷积的时候边界像素不能被卷积，原因在于边界没有完全和kernel重叠，所以当3x3滤波时有1像素边缘没有被处理，当5x5<br>滤波时有2像素边缘没有被处理。
边框类型|效果
----|----
cv::BORDER_CONSTANT|复制指定的常量扩展边界
cv::BORDER_WRAP|复制对边的像素扩展边界
cv::BORDER_REPLICATE|复制边缘的像素扩展边界
cv::BORDER_REFLECT|通过镜像复制扩展边界
cv::BORDER_REFLECT_101|通过镜像复制扩展边界，边界像素除外
cv::BORDER_DEFAULT|cv::BORDER_REFLECT_101的别名
