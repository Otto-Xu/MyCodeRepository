int arrangeCoins(int n){
    
    int i = 1;
    long sum = 1;
    
    while(1)
    {
        if(sum > n)
            return i-1;
        else if(sum == n)
            return i;

        i++;
        sum += i; 
    }

    return -1;
}
