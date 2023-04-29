 bool isPossible(vector<int> &bloomDay,int M,int K, int days) {
        
          int bouquets = 0,count = 0;
          
          for(int i=0;i<bloomDay.size();i++) {
              
                if(bloomDay[i]<= days) {
                    
                    count+=1;
                    
                    if (count >= K) {
                        
                        bouquets +=1;
                        count = 0;
                    }
                    
                } else {
                    
                    count = 0;
                }
                
          }
          return bouquets>=M;
    }
    int solve(int M, int K, vector<int> &bloomDay){
      
          int n = bloomDay.size();
          
          //sort(bloomDay.begin(),bloomDay.end());
          
          if(M*K > n) {
              
              return -1;
          }
          
          int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
          
          int res = -1;
          
          while(low<=high) {
              
              int mid = low + (high-low)/2;
              
              if(isPossible(bloomDay,M,K,mid)) {
                  
                  res = mid;
                  high = mid-1;
              }
              else {
                  
                  low = mid+1;
              }
          }
          
          return res;
    }