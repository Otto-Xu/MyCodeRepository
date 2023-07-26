#### Point类
操作|示例
--------|-----------
默认构造函数|cv::Point2i p;<br>cv::Point3i p;
复制构造函数|cv::Point3f p2(p1);
值构造函数|cv::Point2i(x0, x1);<br>cv::Point3d p(x0, x1, x2);
构造成固定向量类|(cv::Vec3f) p;
成员访问|p.x, p.y, p.z
点乘|float x = p1.dot(p2);
双精度点乘|double x = p1.dot(p2);
叉乘|p1.cross(p2);
判断点p是否在矩形r内|p.inside(r);


#### Scalar类
操作|示例
-----|------
默认构造函数|cv::Scalar s;
复制构造函数|cv::Scalar s2(s1);
值构造函数|cv::Scalar s(x0);<br>cv::Scalar s(x0, x1, x2, x3);
元素相乘|s1.mul(s2);
(四元数)共轭|s.conj(); //(return cv::Scalar(s0, -s1, -s2, -s3))
(四元数)真值测试|s.isReal(); //(return true if s1==s2==s3==0)


#### Size类
操作|示例
----|----
默认构造函数|cv::Size sz;<br>cv::Size2i sz;<br>cv::Size2f sz;
复制构造函数|cv::Size sz2(sz1);
值构造函数|cv::Size2f sz(w, h);
成员访问|sz.width; sz.height;
计算面积|sz.area();
