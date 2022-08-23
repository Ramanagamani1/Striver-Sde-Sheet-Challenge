int f(int ind,int N,vector<int> &price,vector<vector<int>> &dp) {
    if(ind==0){
        return N*price[0];
    }
    if(dp[ind][N]!=-1)
        return dp[ind][N];
    int nottake = 0+f(ind-1,N,price,dp);
    int take=INT_MIN;
    if((ind+1)<=N){
        take = price[ind]+f(ind,N-(ind+1),price,dp);
    }
    return dp[ind][N]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    //vector<vector<int>> dp(n,vector<int>(n+1,0));
    vector<int> prev(n+1,0),cur(n+1,0);
    //return f(n-1,n,price,dp);
    for(int i=0;i<=n;i++)
        prev[i]=i*price[0];
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int nottake = 0+prev[N];
            int take =0;
            if(ind+1<=N)
                take=price[ind]+prev[N-(ind+1)];
            prev[N]=max(take,nottake);
        } 
        //prev=cur;
    }
    return prev[n];
}
