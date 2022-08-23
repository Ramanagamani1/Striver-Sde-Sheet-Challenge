#include<bits/stdc++.h>
int helper(int i,int n,vector<int> &weight, vector<int> &value,int W,vector<vector<int>> &dp) {
    if(i==0){
        if(weight[0]<=W)
            return value[0];
        else
            return 0;
    }
    if(dp[i][W]!=-1)
        return dp[i][W];
    int notpick=0+helper(i-1,n,weight,value,W,dp);
    int pick=INT_MIN;
    if(weight[i]<=W)
        pick=value[i]+helper(i-1,n,weight,value,W-weight[i],dp);
    return dp[i][W]=max(pick,notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return helper(n-1,n,weight,value,maxWeight,dp);
}

/* Tabulation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int j=weight[0];j<=maxWeight;j++){
         dp[0][j]=value[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maxWeight;w++){
            int pick=INT_MIN;
            if(weight[ind]<=w){
                pick=value[ind]+dp[ind-1][w-weight[ind]];
            }
            int notpick=dp[ind-1][w];
            dp[ind][w]=max(pick,notpick);
        }
    }
    return dp[n-1][maxWeight];
    //return helper(n-1,n,weight,value,maxWeight,dp);
}

*/

/*
Space Optimization

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    vector<int> prev(maxWeight+1,0);
    for(int j=weight[0];j<=maxWeight;j++){
         prev[j]=value[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int w=maxWeight;w>=0;w--){
            int pick=INT_MIN;
            if(weight[ind]<=w){
                pick=value[ind]+prev[w-weight[ind]];
            }
            int notpick=prev[w];
            prev[w]=max(pick,notpick);
        }
    }
    return prev[maxWeight];
    //return helper(n-1,n,weight,value,maxWeight,dp);
}

*/
