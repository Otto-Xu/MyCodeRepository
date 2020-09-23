int reverse(int x){
    int max = 0x7fffffff;
    long n = 0;
    while(x != 0)
    {
        n = n*10 + x%10;
        x /= 10;
    }

    if(n > max || n < (-1 * (max + 1)))
        return 0;
    else
        return n; 
}
