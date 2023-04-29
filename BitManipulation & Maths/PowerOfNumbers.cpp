long long power(int N,int R)
    {
       //Your code here
       if(R==0) return 1;
       long long temp = power(N,R/2)%mod;
       if(R%2==1)
            return (temp%mod*temp%mod*N%mod)%mod;
        return (temp%mod*temp%mod)%mod;
        
    }