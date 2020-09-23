int missingNumber(int* nums, int numsSize){
    if(!nums)
        return 0;
    
    int i, j;
    
    int sum = (numsSize+1)*numsSize/2;
    int sum1 = 0, flag;
    
    for(i = 0; i < numsSize; i++, j++)
    {
        if(nums[i] == 0)
            flag = 1;
        
        sum1 += nums[i];
    }
    
    if(flag != 1)
        return 0;
    
    return (sum - sum1);    
}
