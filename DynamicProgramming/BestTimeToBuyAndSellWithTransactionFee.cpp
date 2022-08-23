#include<bits/stdc++.h>
int f(int ind,int buy,int n, int fee, vector<int> &prices, vector<vector<int>> &dp ){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy) {
        profit = max(-prices[ind]+f(ind+1,0,n,fee,prices,dp),f(ind+1,1,n,fee,prices,dp));
    } else {
        profit = max(prices[ind]-fee+f(ind+1,1,n,fee,prices,dp),f(ind+1,0,n,fee,prices,dp));
    }
    return dp[ind][buy]=profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return f(0,1,n,fee,prices,dp);
}
