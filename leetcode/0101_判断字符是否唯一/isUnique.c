bool isUnique(char* astr){
    if(!astr)
        return false;

    char *left = astr;
    char *right = astr + strlen(astr) - 1;
    char *tmp = right;

    while(*left != '\0')
    {
        tmp = right;

        while(*tmp != *left)
        {
            tmp--;
        }

        if(tmp != left)
            return false;
        else
        {
            left++;
            continue;
        }    
    }

    return true;
}
