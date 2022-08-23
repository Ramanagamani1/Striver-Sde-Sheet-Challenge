bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {
	if(target==0)
		return 1;
	if(ind==0)
		return (arr[0]==target);
	if(dp[ind][target]!=-1)
		return dp[ind][target];
	bool take=false;
	if(arr[ind]<=target)
    take=f(ind-1,target-arr[ind],arr,dp);
	bool nottake=f(ind-1,target,arr,dp);
	return dp[ind][target]=take | nottake;
		
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
}

/* Tabulation 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    for(int j=0;j<n;j++){
        dp[j][0]= true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=k;j++){
            bool take=false;
            if(arr[ind]<=j)
            take=dp[ind-1][j-arr[ind]];
            bool nottake=dp[ind-1][j];
            dp[ind][j]=take | nottake;
        }
    }
	//return f(n-1,k,arr,dp);
    return dp[n-1][k];
}
*/

/* Space Optimization

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    vector<bool> prev(k+1,0),cur(k+1,0);
      prev[0]=cur[0]=true;
      prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=k;j++){
            bool take=false;
            if(arr[ind]<=j)
            take=prev[j-arr[ind]];
            bool nottake=prev[j];
           cur[j]=take | nottake;
        }
        prev=cur;
    }
	//return f(n-1,k,arr,dp);
    return prev[k];
}

*/