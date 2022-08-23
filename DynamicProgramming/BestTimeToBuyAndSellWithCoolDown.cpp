#include<bits/stdc++.h>
int f(int ind,int buy,vector<int> &prices,int n, vector<vector<int>> &dp) {
    if(ind>=n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long int profit =0;
    if(buy) {
        profit = max(-prices[ind]+f(ind+1,0,prices,n,dp),f(ind+1,1,prices,n,dp));
    } else {
        profit = max(prices[ind]+f(ind+2,1,prices,n,dp),f(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy]=profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return f(0,1,prices,n,dp);
}

//Tabulation

int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            long int profit =0;
            if(buy) {
                profit = max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
            } else {
                profit = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

// Space Optimization

int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<int> front1(2,0),front2(2,0),cur(2,0);
    for(int ind=n-1;ind>=0;ind--){
               cur[1] = max(-prices[ind]+front1[0], front1[1]);
                cur[0] = max(prices[ind]+front2[1],front1[0]);
            front2=front1;
            front1=cur;
    }
    return cur[1];
}