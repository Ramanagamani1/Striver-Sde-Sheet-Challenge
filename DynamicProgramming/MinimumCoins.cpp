int helper(int ind,int x,vector<int> &num,vector<vector<int>> &dp) {
    if(ind==0){
        if(x%num[0]==0)
            return x/num[0];
        return 1e9;
    }
    if(dp[ind][x]!=-1) return dp[ind][x];
    int nottake = 0 + helper(ind-1,x,num,dp);
    int take=INT_MAX;
    if(num[ind]<=x){
        take = 1 + helper(ind,x-num[ind],num,dp);
    }
    return dp[ind][x]=min(take,nottake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int t=0;t<=x;t++){
        if(t%num[0]==0)
            dp[0][t]=t/num[0];
        else
            dp[0][t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=x;t++){
                int nottake = 0 + dp[ind-1][t];
                int take=INT_MAX;
                if(num[ind]<=t){
                    take = 1 + dp[ind][t-num[ind]];
                }
              dp[ind][t]=min(take,nottake);
        }
    }
    int ans = dp[n-1][x];
    if(ans>=1e9) return -1;
    return ans;
}

/* Space Optimization

	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int t=0;t<=amount;t++) {
              if(t%nums[0]==0)
                   prev[t] = t/nums[0];
              else
                  prev[t] = 1e9;
        }
        for(int ind=1;ind<n;ind++){
        for(int t=0;t<=amount;t++){
                int nottake = 0 + prev[t];
                int take=INT_MAX;
                if(nums[ind]<=t){
                    take = 1 + cur[t-nums[ind]];
                }
              cur[t]=min(take,nottake);
        }
        prev=cur;
    }
    int ans = prev[amount];
      //  int ans = helper(n-1,amount,nums,dp);
        if(ans>=1e9) return -1;
         return ans;
	}

*/