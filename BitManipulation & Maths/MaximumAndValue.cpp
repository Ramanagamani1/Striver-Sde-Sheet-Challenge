int maxAND (int arr[], int N)
    {
        int res = 0;
        for(int bit=31;bit>=0;bit--) {
            
            int pattern = res | (1<<bit);
            int count = 0;
            for(int j=0;j<N;j++) {
                if((arr[j] & pattern) == pattern)
                  count++;
            }
            if (count >=2)
              res = res | (1<<bit);
        }
        return res;
    }