 bool isPowerofTwo(long long n){
        
        // Your code here   
        if (n==0)
           return false;
        int res = n & (n-1);
        return res == 0;
    }