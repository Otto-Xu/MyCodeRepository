# 边界外推和边界处理
### 概述
图像在卷积的时候边界像素不能被卷积，原因在于边界没有完全和kernel重叠，所以当3x3滤波时有1像素边缘没有被处理，当5x5滤波时有2像素边缘没有被处理。
![image](https://github.com/Otto-Xu/MyCodeRepository/blob/master/OpenCv/LearningOpenCv3/10.%20Filters%20and%20Convolution/%E8%BE%B9%E7%BC%98%E5%A4%96%E6%8E%A8.png)
### cv::copyMakeBorder()
边框类型|效果
----|----
cv::BORDER_CONSTANT|复制指定的常量扩展边界
cv::BORDER_WRAP|复制对边的像素扩展边界
cv::BORDER_REPLICATE|复制边缘的像素扩展边界
cv::BORDER_REFLECT|通过镜像复制扩展边界
cv::BORDER_REFLECT_101|通过镜像复制扩展边界，边界像素除外
cv::BORDER_DEFAULT|cv::BORDER_REFLECT_101的别名
### cv::borderInterpolate()
----------------------------------------------------------------------------------------------------------
# 阈值化操作
### cv::threshold()中的thresholdType的可选项
阈值类型|操作
----|----
cv::THRESH_BINARY | DST = (SRC > thresh) ? MAXVALUE : 0
cv::THRESH_BINARY_INV | DST = (SRC > thresh) ? 0 : MAXVALUE
cv::THRESH_TRUNC | DST = (SRC > thresh) ? THRESH : SRC
cv::THRESH_TOZERO | DST = (SRC > thresh) ? SRC : 0
cv::THRESH_TOZERO_INV | DST = (SRC > thresh) ? 0 : SRC

----------------------------------------------------------------------------------------------------------
# Otsu算法
----------------------------------------------------------------------------------------------------------
# 自适应阈值
### 概述
相比于一般的阈值化操作，当图像中出现较大的明暗差异时，自适应阈值是非常有效的。
