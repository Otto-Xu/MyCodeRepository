/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 2);
    memset(arr, 0, sizeof(int) * 2);
    *returnSize = 2;

    int *front = nums;
    int *rear = nums + numsSize - 1;

    while(*front != *rear)
    {
        if((*front + *rear) == target)
        {
            arr[0] = *front;
            arr[1] = *rear;
            break;
        }
        else if((*front + *rear) > target)
        {
            rear--;
        }
        else if((*front + *rear) < target)
        {
            front++;
        }
    }

    return arr;
}
