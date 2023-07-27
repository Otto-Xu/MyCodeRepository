-----------------------------------------------------------------------------------------------------------------------------------
# TermCriteria类
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
### Note:
1.某些算法需要一个终止条件以确定何时退出。  
2.终止条件的形式：达到允许的有限迭代次数，或者在一定误差内接近某个需求值，或者同时满足以上两个条件。

-----------------------------------------------------------------------------------------------------------------------------------
#
###
###
-----------------------------------------------------------------------------------------------------------------------------------
#
###
###
-----------------------------------------------------------------------------------------------------------------------------------
#
###
###
-----------------------------------------------------------------------------------------------------------------------------------
#
###
###
-----------------------------------------------------------------------------------------------------------------------------------
#
###
###
-----------------------------------------------------------------------------------------------------------------------------------
