int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> after(2,vector<int>(k+1,0));
    vector<vector<int>> cur(2,vector<int>(k+1,0));
    for(int ind=n-1;ind>=0;ind--) {
          for(int buy=0;buy<2;buy++) {
              for(int cap=1;cap<=k;cap++) {
                    if(buy==1){
                            cur[buy][cap] = max(-prices[ind]+after[0][cap], 0+after[1][cap]);
                        } else
                            cur[buy][cap] = max(prices[ind]+after[1][cap-1], 0+after[0][cap]);
              }
          }
        after=cur;
    }
    return after[1][k];
}

// Space Optimization  using 1d array - memoization

#include<bits/stdc++.h>
int f(int ind,int trans,vector<int> &prices, int n, int k,vector<vector<int>> &dp) {
    if(ind==n || trans==2*k) return 0;
    
    if(dp[ind][trans]!=-1)
        return dp[ind][trans];
    
    if(trans%2==0) // buy 
    {
        return dp[ind][trans]=max(-prices[ind]+f(ind+1,trans+1,prices,n,k,dp), 0+f(ind+1,trans,prices,n,k,dp));
    }
       return dp[ind][trans]=max(prices[ind]+f(ind+1,trans+1,prices,n,k,dp), 0+f(ind+1,trans,prices,n,k,dp));
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
   vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
   return f(0,0,prices,n,k,dp);
    
}

// using 1d array transaction arr- tabulation
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
   vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
   //return f(0,0,prices,n,k,dp);
   
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=2*k-1;trans>=0;trans--) {
            if(trans%2==0) // buy 
    {
        dp[ind][trans]=max(-prices[ind]+dp[ind+1][trans+1], 0+dp[ind+1][trans]);
    } else{
    dp[ind][trans]=max(prices[ind]+dp[ind+1][trans+1], 0+dp[ind+1][trans]);
            }
        }
    }
    return dp[0][0];
}

// Space optimization - using 1d transactionarr

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
   //vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
   //return f(0,0,prices,n,k,dp);
   vector<int> after(2*k+1,0), cur(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=2*k-1;trans>=0;trans--) {
            if(trans%2==0) // buy 
    {
        cur[trans]=max(-prices[ind]+after[trans+1], 0+after[trans]);
    } else{
    cur[trans]=max(prices[ind]+after[trans+1], 0+after[trans]);
            }
        }
        after=cur;
    }
    return after[0];
}




// Iterative

 int maxProfit(int B, vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        if(B>n){
            B=n/2;
        }
        int profit[B+1][n+1];

        for(int i=0;i<=B;i++)
          profit[i][0]=0;

        for(int i=0;i<=n;i++)
          profit[0][i]=0;


        for(int k=1;k<=B;k++){
            int prevDiff=INT_MIN;
            for(int i=1;i<n;i++){
                prevDiff=max(prevDiff,profit[k-1][i-1]-prices[i-1]);
                profit[k][i]=max(profit[k][i-1],prevDiff+prices[i]);
            }
        }
        return profit[B][n-1];
    }