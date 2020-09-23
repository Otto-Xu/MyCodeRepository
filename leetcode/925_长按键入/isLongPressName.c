bool isLongPressedName(char * name, char * typed){
    if(!name || !typed)
        return false;

    int i = 0, j = 0;
    
    while(name[i] != '\0' && typed[j] != 0)
    {
        if(name[i] == typed[j])
        {
            i++;
        }

        j++;
    }    

    return name[i] == '\0';
}
