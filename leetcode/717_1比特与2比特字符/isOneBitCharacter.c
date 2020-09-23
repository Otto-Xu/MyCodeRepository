bool isOneBitCharacter(int* bits, int bitsSize){

    int i = 0;

    while(i < bitsSize - 1)
    {
        if(bits[i] == 0)
        {
            i++;
        }
        else if(bits[i] == 1)
        {
            i += 2;
        }
    }

    if(i == bitsSize -1)
        return true;
    else   
        return false;

}
