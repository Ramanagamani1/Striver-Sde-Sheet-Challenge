 bool isPossible(int nums[],int N, int wt, int D) {
        
        int days = 1 , sum = 0;
        
        for(int i=0;i<N;i++) {
            
            if(sum + nums[i] > wt) {
                
                days += 1;
                
                if (nums[i]> wt || days>D) return false;
                
                sum = nums[i];
            } else {
                
                sum+=nums[i];
            }
        }
        return (days<=D);
        
    }
    int leastWeightCapacity(int nums[], int N, int D) {
       
        int low = 1;
        int high = 0;
        
        for(int i=0;i<N;i++){
            high += nums[i];
        }
        
        int res = 1;
        
        while(low<=high) {
            
            int mid = low+ (high-low)/2;
            
            if(isPossible(nums,N,mid,D)) {
                
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return res;
    }
};