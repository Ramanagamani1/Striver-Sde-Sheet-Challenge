 long long divide(long long dividend, long long divisor) 
    {
        long long q = 0;
        long long sign = ((divisor<0) ^ (dividend<0)) ? -1:1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        for(int i=31;i>=0;i--) {
             long long temp = (divisor<<i);
             if (temp <= dividend) {
                  dividend -= temp;
                  q |= (1<<i);
             }
        }
        return sign*q;
    }