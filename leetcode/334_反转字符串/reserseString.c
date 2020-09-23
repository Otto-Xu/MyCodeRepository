void reverseString(char* s, int sSize){
    if(!s)
        return;
    
    char tmp;
    int i;
    
    for(i = 0; i < sSize/2; i++)
    {
        tmp = s[i];
        s[i] = s[sSize-1-i];
        s[sSize-1-i] = tmp;
    }
    
    return ;
}
