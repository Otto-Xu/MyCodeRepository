-----------------------------------------------------------------------------------------------------------------------------------
# cv::TermCriteria类
### 定义
```
class CV_EXPORTS TermCriteria
{
public:
    /**
      Criteria type, can be one of: COUNT, EPS or COUNT + EPS
    */
    enum Type
    {
        COUNT=1, //!< the maximum number of iterations or elements to compute
        MAX_ITER=COUNT, //!< ditto
        EPS=2 //!< the desired accuracy or change in parameters at which the iterative algorithm stops
    };

    //! default constructor
    TermCriteria();
    /**
    @param type The type of termination criteria, one of TermCriteria::Type
    @param maxCount The maximum number of iterations or elements to compute.
    @param epsilon The desired accuracy or change in parameters at which the iterative algorithm stops.
    */
    TermCriteria(int type, int maxCount, double epsilon);

    inline bool isValid() const
    {
        const bool isCount = (type & COUNT) && maxCount > 0;
        const bool isEps = (type & EPS) && !cvIsNaN(epsilon);
        return isCount || isEps;
    }

    int type; //!< the type of termination criteria: COUNT, EPS or COUNT + EPS
    int maxCount; //!< the maximum number of iterations/elements
    double epsilon; //!< the desired accuracy
};
```
### Note
1.某些算法需要一个终止条件以确定何时退出。  
2.终止条件的形式：达到允许的有限迭代次数，或者在一定误差内接近某个需求值，或者同时满足以上两个条件。

-----------------------------------------------------------------------------------------------------------------------------------
# cv::Range类
### 定义
```
class CV_EXPORTS Range
{
public:
    Range();
    Range(int _start, int _end);
    int size() const;
    bool empty() const;
    static Range all();

    int start, end;
};
```
### Note  
1.Range类用于确定一个连续的整数序列。  
2.表示范围从start到end，包含start，但不包含end。  

-----------------------------------------------------------------------------------------------------------------------------------
# cv::Ptr智能指针类和垃圾回收
### 定义
```
template<typename T>
struct Ptr : public std::shared_ptr<T>
{
#if 0
    using std::shared_ptr<T>::shared_ptr;  // GCC 5.x can't handle this
#else
    inline Ptr() CV_NOEXCEPT : std::shared_ptr<T>() {}
    inline Ptr(nullptr_t) CV_NOEXCEPT : std::shared_ptr<T>(nullptr) {}
    template<typename Y, typename D> inline Ptr(Y* p, D d) : std::shared_ptr<T>(p, d) {}
    template<typename D> inline Ptr(nullptr_t, D d) : std::shared_ptr<T>(nullptr, d) {}

    template<typename Y> inline Ptr(const Ptr<Y>& r, T* ptr) CV_NOEXCEPT : std::shared_ptr<T>(r, ptr) {}

    inline Ptr(const Ptr<T>& o) CV_NOEXCEPT : std::shared_ptr<T>(o) {}
    inline Ptr(Ptr<T>&& o) CV_NOEXCEPT : std::shared_ptr<T>(std::move(o)) {}

    template<typename Y> inline Ptr(const Ptr<Y>& o) CV_NOEXCEPT : std::shared_ptr<T>(o) {}
    template<typename Y> inline Ptr(Ptr<Y>&& o) CV_NOEXCEPT : std::shared_ptr<T>(std::move(o)) {}
#endif
    inline Ptr(const std::shared_ptr<T>& o) CV_NOEXCEPT : std::shared_ptr<T>(o) {}
    inline Ptr(std::shared_ptr<T>&& o) CV_NOEXCEPT : std::shared_ptr<T>(std::move(o)) {}

    // Overload with custom DefaultDeleter: Ptr<IplImage>(...)
    template<typename Y>
    inline Ptr(const std::true_type&, Y* ptr) : std::shared_ptr<T>(ptr, DefaultDeleter<Y>()) {}

    // Overload without custom deleter: Ptr<std::string>(...);
    template<typename Y>
    inline Ptr(const std::false_type&, Y* ptr) : std::shared_ptr<T>(ptr) {}

    template<typename Y = T>
    inline Ptr(Y* ptr) : Ptr(has_custom_delete<Y>(), ptr) {}

    // Overload with custom DefaultDeleter: Ptr<IplImage>(...)
    template<typename Y>
    inline void reset(const std::true_type&, Y* ptr) { std::shared_ptr<T>::reset(ptr, DefaultDeleter<Y>()); }

    // Overload without custom deleter: Ptr<std::string>(...);
    template<typename Y>
    inline void reset(const std::false_type&, Y* ptr) { std::shared_ptr<T>::reset(ptr); }

    template<typename Y>
    inline void reset(Y* ptr) { Ptr<T>::reset(has_custom_delete<Y>(), ptr); }

    template<class Y, class Deleter>
    void reset(Y* ptr, Deleter d) { std::shared_ptr<T>::reset(ptr, d); }

    void reset() CV_NOEXCEPT { std::shared_ptr<T>::reset(); }

    Ptr& operator=(const Ptr& o) { std::shared_ptr<T>::operator =(o); return *this; }
    template<typename Y> inline Ptr& operator=(const Ptr<Y>& o) { std::shared_ptr<T>::operator =(o); return *this; }

    T* operator->() const CV_NOEXCEPT { return std::shared_ptr<T>::get();}
    typename std::add_lvalue_reference<T>::type operator*() const CV_NOEXCEPT { return *std::shared_ptr<T>::get(); }

    // OpenCV 3.x methods (not a part of standard C++ library)
    inline void release() { std::shared_ptr<T>::reset(); }
    inline operator T* () const { return std::shared_ptr<T>::get(); }
    inline bool empty() const { return std::shared_ptr<T>::get() == nullptr; }

    template<typename Y> inline
    Ptr<Y> staticCast() const CV_NOEXCEPT { return std::static_pointer_cast<Y>(*this); }

    template<typename Y> inline
    Ptr<Y> constCast() const CV_NOEXCEPT { return std::const_pointer_cast<Y>(*this); }

    template<typename Y> inline
    Ptr<Y> dynamicCast() const CV_NOEXCEPT { return std::dynamic_pointer_cast<Y>(*this); }
};
```
### Note
1.cv::Ptr类就看成一个cv的一个智能指针,在适当的时间能自动删除指向的对象；工作机制很像C++的内置指针


-----------------------------------------------------------------------------------------------------------------------------------
# cv::Exception类和异常处理
### 定义
```
class CV_EXPORTS Exception : public std::exception
{
public:
    /*!
     Default constructor
     */
    Exception();
    /*!
     Full constructor. Normally the constructor is not called explicitly.
     Instead, the macros CV_Error(), CV_Error_() and CV_Assert() are used.
    */
    Exception(int _code, const String& _err, const String& _func, const String& _file, int _line);
    virtual ~Exception() throw();

    /*!
     \return the error description and the context as a text string.
    */
    virtual const char *what() const throw() CV_OVERRIDE;
    void formatMessage();

    String msg; ///< the formatted error message

    int code; ///< error code @see CVStatus
    String err; ///< error description
    String func; ///< function name. Available only when the compiler supports getting it
    String file; ///< source file name where the error has occurred
    int line; ///< line number in the source file where the error has occurred
};
```
### Node
1.cv::Exception继承STL的异常类std::exception, 其使用方法一样

-----------------------------------------------------------------------------------------------------------------------------------
# cv::DataType<>模板
### 定义
```
template<typename _Tp> class DataType
{
public:
#ifdef OPENCV_TRAITS_ENABLE_DEPRECATED
    typedef _Tp         value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 1,
           depth        = -1,
           channels     = 1,
           fmt          = 0,
           type = CV_MAKETYPE(depth, channels)
         };
#endif
};
```
### Node
1.当OpenCV库函数需要传递特定数据类型的概念时，它们会创建一个​​cv::DataType<>​​​类型的对象。​​cv::DataType<>​​本身是一个模板，传递的实际对象是这个模板的特化。


-----------------------------------------------------------------------------------------------------------------------------------
