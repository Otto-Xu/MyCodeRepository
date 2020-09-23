int thirdMax(int* nums, int numsSize){
    int min = nums[0];
    for(int i = 0; i < numsSize; i++)
    {
        if(min > nums[i])
            min = nums[i];
    }
    
    int first = min,
        second = min,
        third = min;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        else if(nums[i] > second && nums[i] != first)
        {
            third = second;
            second = nums[i];
        }
        else if(nums[i] > third && nums[i] != second && nums[i] != first)
        {
            third = nums[i];
        }
    }    

    if(third == second)
        return first;
    else    
        return third;
}
