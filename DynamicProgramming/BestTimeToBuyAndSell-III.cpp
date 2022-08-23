#include<bits/stdc++.h>
int f(int ind,int buy, int cap, vector<int> &prices,int n, vector<vector<vector<int>>> &dp){
    if(cap==0 || ind==n) return 0;
    
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
   
    if(buy==1){
        return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1,0,cap,prices,n,dp), 0+f(ind+1,1,cap,prices,n,dp));
    } 
        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp), 0+f(ind+1,0,cap,prices,n,dp));
    
    
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
}

// Tabulation

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //return f(0,1,2,prices,n,dp);
    for(int ind=n-1;ind>=0;ind--) {
          for(int buy=0;buy<2;buy++) {
              for(int cap=1;cap<3;cap++) {
                    if(buy==1){
                            dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap], 0+dp[ind+1][1][cap]);
                        } else
                            dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
              }
          }
    }
    return dp[0][1][2];
}

// Iterative

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<int> left(n),right(n);
        int leftmin=prices[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],prices[i]-leftmin);
            leftmin=min(leftmin,prices[i]);
        }
        int rightmax=prices[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],rightmax-prices[i]);
            rightmax=max(rightmax,prices[i]);
        }
        int profit=right[0];
        for(int i=1;i<n;i++){
            profit=max(profit,left[i-1]+right[i]);
        }
        return profit;
    }

// Space
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> cur(2,vector<int>(3,0));
    for(int ind=n-1;ind>=0;ind--) {
          for(int buy=0;buy<2;buy++) {
              for(int cap=1;cap<3;cap++) {
                    if(buy==1){
                            cur[buy][cap] = max(-prices[ind]+after[0][cap], 0+after[1][cap]);
                        } else
                            cur[buy][cap] = max(prices[ind]+after[1][cap-1], 0+after[0][cap]);
              }
          }
        after=cur;
    }
    return after[1][2];
}