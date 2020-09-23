/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *target = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    memset(target, -1, sizeof(int) * numsSize);
    
    for(int i = 0; i < numsSize; i++)
    {
        if(target[index[i]] == -1)
            target[index[i]] = nums[i];
        else
        {
            for(int j = numsSize-1; j >= index[i] && j < numsSize && j-1 >= 0; j--)
            {
                target[j] = target[j-1];
            }
            target[index[i]] = nums[i];
        }
    }
    
    return target;
}
