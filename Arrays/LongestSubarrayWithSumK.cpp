int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
         int presum = 0 , len = 0;
         unordered_map<int,int> mp;
         
         for(int i=0;i<n;i++) {
              presum+=arr[i];
              
              if(presum==k){
                  len = i+1;
              }
              
              if(mp.find(presum)==mp.end()) {
                    mp[presum] = i;
              }
              
              if(mp.find(presum-k)!=mp.end()) {
                   
                   if(len < i-mp[(presum-k)])
                     len = i- mp[presum-k];
              }
         }
         return len;
    } 
