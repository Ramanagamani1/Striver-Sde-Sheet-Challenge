bool isSparse(int n)
    {
        // Your code
        int count = 0, ans= 0;
        while (n>0) {
            if(n&1) {
                count+=1;
            } else
            count = 0;
            ans = max(ans,count);
            n = n/2;
        }
        return ans<2;
    }

or

    return (n & (n>>1) == 0 )