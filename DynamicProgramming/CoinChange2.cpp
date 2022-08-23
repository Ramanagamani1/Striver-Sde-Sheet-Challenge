#include<bits/stdc++.h>
long helper(int ind,int x,int *num,vector<vector<long>> &dp) {
    if(ind==0){
        return (x%num[0]==0);
    }
    if(dp[ind][x]!=-1) return dp[ind][x];
    long nottake = helper(ind-1,x,num,dp);
    long take=0;
    if(num[ind]<=x){
        take = helper(ind,x-num[ind],num,dp);
    }
    return dp[ind][x]=take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return helper(n-1,value,denominations,dp);
}

/* Memoization

 int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long>> dp(n,vector<long>(amount+1,0));
        for(int t=0;t<=amount;t++) {
              dp[0][t] = (t%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++) {
            for(int t=0;t<=amount;t++) {
                int nottake = dp[ind-1][t];
                int take=0;
                if(coins[ind]<=t)
                    take = dp[ind][t-coins[ind]];
                dp[ind][t]= take + nottake;
            }
        }
        return dp[n-1][amount];
    }

*/

/* Space Optimization

int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //vector<vector<long>> dp(n,vector<long>(amount+1,0));
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int t=0;t<=amount;t++) {
              prev[t] = (t%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++) {
            for(int t=0;t<=amount;t++) {
                int nottake = prev[t];
                int take=0;
                if(coins[ind]<=t)
                    take = cur[t-coins[ind]];
                cur[t]= take + nottake;
            }
            prev=cur;
        }
        return prev[amount];
    }

*/