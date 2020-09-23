bool CheckPermutation(char* s1, char* s2){
    int arr[26] = {0};

    for(int i = 0; i < strlen(s1); i++)
        arr[s1[i] - 'a'] += s1[i];
    for(int i = 0; i < strlen(s2); i++)
        arr[s2[i] - 'a'] -= s2[i];
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] != 0)
            return false;
    }

    return true;

}
