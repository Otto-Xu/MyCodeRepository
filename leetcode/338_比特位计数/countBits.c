/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int *array = (int *)malloc(sizeof(int)*(num+1));
    int *ret = array;
    int count, tmp, i, j;
    
    for(i = 0; i <= num; i++)
    {
        j = i;
        count = 0;
        
        while(j)
        {
            tmp = j&1;
            
            if(tmp == 1)
                count++;
            
            j = j >> 1;
        }
        
        *array++ = count;
    }
    
    *returnSize = num+1;
    
    return ret;
}
