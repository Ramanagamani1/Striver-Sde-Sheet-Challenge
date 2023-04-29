class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;

        unordered_set<int> mp;

        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }

        for(int i=0;i<nums.size();i++) {
            int count = 1;
            if(mp.find(nums[i]-1)==mp.end()) {
                   
                   while(mp.find(nums[i]+count)!=mp.end())
                      count+=1;
                    res = max(res,count);
              }
        }
        return res;
    }
};