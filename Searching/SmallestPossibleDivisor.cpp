bool isPossible(vector<int>& nums,int N,int speed, int k) {
        
        int time = 0;
        
        for(int i=0;i<N;i++) {
            
            if(nums[i]%speed == 0) {
                
                time += nums[i]/speed;
            } else {
                
                time += nums[i]/speed + 1;
            }
        }
        if (time<=k) {
            return true;
        }
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int K) {

        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        
        int res = 1;
        
        int N = nums.size();
        
        while(low<=high) {
            
            int mid = low+ (high-low)/2;
            
            if(isPossible(nums,N,mid,K)) {
                
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