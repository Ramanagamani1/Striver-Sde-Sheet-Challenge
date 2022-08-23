#include<bits/stdc++.h>
long f(int ind,int buy,long *values,int n,vector<vector<long>> &dp) {
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit = 0;
    if(buy) {
        profit = max(-values[ind]+f(ind+1,0,values,n,dp),
                     0+f(ind+1,1,values,n,dp));
    } else {
        profit = max(values[ind]+f(ind+1,1,values,n,dp),
                     0+f(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0,1,values,n,dp);
}

//Tabulation

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    //return f(0,1,values,n,dp);
    dp[n][1]=0;
    dp[n][0]=0;
    for(int ind=n-1;ind>=0;ind--){
          for(int buy=0;buy<2;buy++) {
                long profit = 0;
                if(buy) {
                    profit = max(-values[ind]+dp[ind+1][0],
                                 0+dp[ind+1][1]);
                } else {
                    profit = max(values[ind]+dp[ind+1][1],
                                 0+dp[ind+1][0]);
                }
               dp[ind][buy]=profit;
          }
    }
    return dp[0][1];
}

// space
long getMaximumProfit(long *values, int n)
{
    vector<long> next(2,0), cur(2,0);
    next[0]=next[1]=0;
    for(int ind=n-1;ind>=0;ind--){
          for(int buy=0;buy<2;buy++) {
                long profit = 0;
                if(buy) {
                    profit = max(-values[ind]+next[0],
                                 0+next[1]);
                } else {
                    profit = max(values[ind]+next[1],
                                 0+next[0]);
                }
               cur[buy]=profit;
          }
          next = cur;
    }
    return next[1];
}

// using four variables

long getMaximumProfit(long *values, int n)
{
    long nextNotBuy, nextBuy, curNotBuy, curBuy;
    nextNotBuy = nextBuy =0;
    for(int ind=n-1;ind>=0;ind--){
                    curBuy = max(-values[ind]+nextNotBuy,
                                 0+nextBuy);
                    curNotBuy = max(values[ind]+nextBuy,
                                 0+nextNotBuy);
          nextBuy=curBuy;
         nextNotBuy= curNotBuy;
    }
    return nextBuy;
}


// iterative
 int maxProfit(vector<int>& prices) {
        // Valley peak approach
        int i=0;
        int n=prices.size();
        if(n==1)
          return 0;
        int profit=0;
        while(i<n-1){
            while((i<n-1) && prices[i+1]<=prices[i])
                i++;
            if(i==n-1)
               break;
            int buy=i++;
            while(i<n && prices[i]>=prices[i-1])
               i+=1;
            int sell=i-1;
            profit+=prices[sell]-prices[buy];

        }
         return profit;
        }
