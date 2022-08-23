int mod=(int)1e9+7;
int f(int ind,int k,vector<int> &num,vector<vector<int>> &dp){
	if(ind==0) {
	    if(k==0 && num[0]==0) return 2;
		if(k==0 || k==num[0])
		  return 1;
		return 0;
    }
	if(dp[ind][k]!=-1)
		return dp[ind][k];
	int notpick=f(ind-1,k,num,dp);
	int pick=0;
	if(num[ind]<=k)
		pick=f(ind-1,k-num[ind],num,dp);
	return dp[ind][k]=(pick+notpick)%mod;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,-1));
	return f(n-1,tar,num,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
	int totalsum=0;
	for(int i=0;i<n;i++)
		totalsum+=arr[i];
	if(totalsum-d < 0 || (totalsum-d)%2==1) return 0;
	return findWays(arr,(totalsum-d)/2);
}


