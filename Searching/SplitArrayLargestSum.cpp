class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int n,int s) {

        int sum = 0, d = 1;

        for(int i=0;i<n;i++) {

            if(sum+nums[i] > s) {

                d+=1;
                
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return (d<=k);
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(),nums.end());

        int sum = 0, n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int high = sum;
        int res = 0;

        while(low<=high) {

            int mid = low + (high-low)/2;

            if (isPossible(nums,k,n,mid)) {

                   res = mid;
                   high = mid-1;
            } else {

                low = mid+1;
            }
        }
        return res;
    }
};