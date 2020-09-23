int longestPalindrome(char * s){
    int arr[26] = {0};
    int ARR[26] = {0};
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            arr[s[i] - 'a']++;
        if(s[i] >= 'A' && s[i] <= 'Z' )
            ARR[s[i] - 'A']++;   
    }

    int max_flag = -1, MAX_FLAG = -1;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] % 2 != 0 && arr[i] > max_flag)
            max_flag = i;

        if(ARR[i] % 2 != 0 && ARR[i] > MAX_FLAG)
            MAX_FLAG = i;    
    }
    if(max_flag >= MAX_FLAG)
        MAX_FLAG = -1;
    else
        max_flag = -1;

    int sum = 0;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] % 2 == 0 || max_flag == i)
            sum += arr[i];
        else if(arr[i] % 2 != 0 && max_flag != i)
            sum += arr[i] - 1;

        if(ARR[i] % 2 == 0 || MAX_FLAG == i)
            sum += ARR[i];
        else if(ARR[i] % 2 != 0 && MAX_FLAG != i)
            sum += ARR[i] - 1;    
    }

    return sum;
}
