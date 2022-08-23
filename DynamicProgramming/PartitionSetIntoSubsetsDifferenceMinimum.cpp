int minSubsetSumDifference(vector<int>& arr, int n)
{
   int totalsum=0;
   for(int i=0;i<n;i++) totalsum+=arr[i];
   int k=totalsum;
   vector<vector<bool>> dp(n,vector<bool>(k+1,0));
   for(int i=0;i<n;i++)
	   dp[i][0]= true;
	if(arr[0]<=k) dp[0][arr[0]]=true;
	for(int i=1;i<n;i++){
		for(int target=1;target<=k;target++){
			bool nottake= dp[i-1][target];
			bool take=false;
			if(arr[i]<=target)
				take=dp[i-1][target-arr[i]];
			dp[i][target]=take | nottake;
		}
	}
	int mini=1e9;
	for(int i=0;i<=k/2;i++){
		if(dp[n-1][i]==true)
		  mini=min(mini,abs(i-(totalsum-i)));
	}
	return mini;
}
