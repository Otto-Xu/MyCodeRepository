/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    if(!S)
        return NULL;

    int N = strlen(S);
    int *arr = (int *)malloc(sizeof(int) * (N+1));
    *returnSize = N + 1;

    int i = 0;
    int left = 0, right = N;
    while(left != right)
    {
        if(S[i] == 'I')
        {
            *arr = left;
            left++;
        }
        else if(S[i] == 'D')
        {
            *arr = right;
            right--;
        }
        arr++;
        i++;
    }
    *arr = right;

    arr -= N;
    return arr;
}
