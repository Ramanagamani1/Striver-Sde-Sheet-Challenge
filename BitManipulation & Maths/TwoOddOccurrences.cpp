vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        int x = Arr[0];
        for(int i=1;i<N;i++) {
            x = x^Arr[i];
        }
        int k = (x & (~(x-1))); // finds the number which has only one bit set and set bit corresponds to lastbit of x;
        
        int xor1 = 0, xor2= 0;
        for(int i=0;i<N;i++) {
            if ( (Arr[i] & k) != 0)
              xor1 = xor1^Arr[i];
              else
                xor2 = xor2^Arr[i];
        }
        
        if (xor1>xor2){
            return {xor1,xor2};
        }
        else 
        return {xor2,xor1};
    }