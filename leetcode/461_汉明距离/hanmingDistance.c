int hammingDistance(int x, int y){
    int a = x^y;
    int distance = 0;
    
    /*
    while(a)
    {
        if(a%2 == 1)
            distance++;
        
        a = a/2;
    }
    */
    
    while(a)
    {
        if(a & 1 == 1)
            distance++;
        
        a = a >> 1;
    }
   
    
    return distance;
}
