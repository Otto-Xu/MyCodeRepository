#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myprintf(int *a, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n-------------\n");
}

int func(int *nums, int numsSize, int k)
{
    int i, index;
    int ans = -1;

    if(numsSize > 1)
    {
        //构造哈希表，并初始化置为-1
        //用哈希表来存储nums数组中各个元素的下标
        //若发现nums[hash[index]] == nums[i]，即元素数值相同
        //但i != hash[index]，元素下标不同
        //即可进行判断是否两者距离最大不超过差值k
        int *hash = (int *)malloc(numsSize * sizeof(int));
        memset(hash, -1, numsSize * sizeof(int));
        
        for(i = 0; i < numsSize; i++)
        {
            index = nums[i] % numsSize;
            printf("1index: %d\n", index);
            index = index < 0 ? index + numsSize -1 : index;

            if(hash[index] != -1)
            {
                printf("nums[hash[index]]: %d\n", nums[hash[index]]);
                printf("nums[i]: %d\n", nums[i]);
                printf("i: %d\n", i);
                printf("index: %d\n", index);
                while(nums[hash[index]] != nums[i])
                {
                    printf("2index: %d\n", index);
                    //线性探测法
                    ++index;
                    index %= numsSize;
                    if(hash[index] == -1)
                        hash[index] = i;
                }
                if(i != hash[index])
                {
                    if(i - hash[index] <= k)
                    {
                        ans = 0;
                        break;
                    }
                    else
                        hash[index] = i;
                }
            }
            else
                hash[index] = i;

            myprintf(hash, numsSize);    
        }
    }
    
    printf("%d\n", ans);

    return 0;
}

int main()
{
    int nums[6] = {1,7,13,19,13,1};
    int res;
    res = func(nums, sizeof(nums)/sizeof(nums[0]), 2);

    return 0;
}
