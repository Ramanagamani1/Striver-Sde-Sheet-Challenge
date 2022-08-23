int findmaximum(int ind,vector<int> &dp,vector<int> &nums) {
	if(ind==0)
		return nums[ind];
	if(ind<0)
		return 0;
	if(dp[ind]!=-1)
		return dp[ind];
	int pick = nums[ind] + findmaximum(ind-2,dp,nums);
	int notpick = findmaximum(ind-1,dp,nums);
	return dp[ind] = max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
// 	if(nums.size()==1)
// 		return nums[]
	vector<int> dp(nums.size(),-1);
	return findmaximum(nums.size()-1,dp,nums);
	
}