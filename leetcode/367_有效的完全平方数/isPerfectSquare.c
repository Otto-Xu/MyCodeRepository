bool isPerfectSquare(int num){
    
    long n = 1;
    long i = 1;
    while(1)
    {
        if(n == num)
            return true;
        else if(n > num)
            break;

        n += (2*i + 1);
        i++;     
    }

    return false;
}
