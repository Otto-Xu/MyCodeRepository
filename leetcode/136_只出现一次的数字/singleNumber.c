int singleNumber(int* nums, int numsSize)
{
    if(!nums)
	return 0;

	int i;
	int target = 0;
	
	for(i = 0; i < numsSize; i++)
	{
		target ^= nums[i];
	}

	return target;
}
