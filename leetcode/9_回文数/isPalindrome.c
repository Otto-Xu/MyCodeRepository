bool isPalindrome(int x){
    if(x < 0)
        return false;

    int x1 = x;
    long n = 0;
    while(x1 != 0)
    {
        n = n*10 + x1%10;
        x1 /= 10;
    }    
    if(x == n)
        return true;
    else 
        return false;
}
