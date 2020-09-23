int findDuplicate(int* nums, int numsSize){
    if(!nums)
        return 0;
    
    int *array = (int *)malloc(sizeof(int)*numsSize);
    array = nums;
    
    int i = 0;
    int tmp;
    
    while(i < numsSize)
    {
        if(nums[i] != i+1 && nums[i] != nums[nums[i]-1])
        {
            tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
            continue;
        }
        else if(nums[i] != i+1 && nums[i] == nums[nums[i]-1])
            return nums[i];
        
        i++;
    }
    
    return -1;
}
