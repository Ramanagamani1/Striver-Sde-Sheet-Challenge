int f(int ind,int k,vector<int> &num,vector<vector<int>> &dp){
	if(k==0)
		return 1;
	if(ind==0)
        return (num[0]==k);
	if(dp[ind][k]!=-1)
		return dp[ind][k];
	int notpick=f(ind-1,k,num,dp);
	int pick=0;
	if(num[ind]<=k)
		pick=f(ind-1,k-num[ind],num,dp);
	return dp[ind][k]=pick+notpick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,-1));
	return f(n-1,tar,num,dp);
}

/* Tabultaion
int findWays(vector<int> &arr, int tar)
{
    // Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=tar){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=tar;t++){
            int pick=0;
            if(arr[i]<=t){
                pick=dp[i-1][t-arr[i]];
            }
            int notpick=dp[i-1][t];
            dp[i][t]=pick+notpick;
        }
    }
    return dp[n-1][tar];
	//return f(n-1,tar,num,dp);
}

*/

/* Space Optimization
int findWays(vector<int> &arr, int tar)
{
    // Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(tar+1,0));
    vector<int> prev(tar+1,0),cur(tar+1,0);
     prev[0]=cur[0]=1;
     if(arr[0]<=tar){
         prev[arr[0]]=1;
     }
    for(int i=1;i<n;i++){
        for(int t=1;t<=tar;t++){
            int pick=0;
            if(arr[i]<=t){
                pick=prev[t-arr[i]];
            }
            int notpick=prev[t];
            cur[t]=pick+notpick;
        }
        prev=cur;
    }
    return prev[tar];
	//return f(n-1,tar,num,dp);
}

*/