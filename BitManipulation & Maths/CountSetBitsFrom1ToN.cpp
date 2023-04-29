int largestPowerOf2(int n) {
        int x = 0;
        while ( (1<<x) <=n ) {
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0)
          return 0;
        // count largest power of 2 from 1 to n
        int x = largestPowerOf2(n);
        // (2^(x-1)*x + n-(2^x)+1 + countSetBits(n-(2^x)))
        return (1<<(x-1))*x + (n-(1<<x)+1) + countSetBits(n-(1<<x));
    } 



or

/*
int countBits(int n) {
        int res = 0;
        while(n>0) {
            n = n & (n-1);
            res = res + 1;
        }
        return res;
    }
    int countSetBits(int n)
    {
        // Your logic here
        int res = 0;
        for(int i=1;i<=n;i++)
          res = res+ countBits(i);
        return res;
    }

*/