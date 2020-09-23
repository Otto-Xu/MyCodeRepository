int firstUniqChar(char * s){
    if(!s)
        return -1;
    
    int len = strlen(s);
    int index = 0;
    int i;
    
    for(i = 0; i < len; )
    {
        if(index != i && s[index] == s[i])
        {
            index++;
            i = 0;
            continue;
        }
        
        i++;
    }
    
    if(index < len && len >= 1)
        return index;
    
    return -1;
}
