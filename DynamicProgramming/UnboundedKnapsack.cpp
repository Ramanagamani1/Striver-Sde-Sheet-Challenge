#include<bits/stdc++.h>
int helper(int ind,int w,vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if(ind==0){
        if(weight[0]<=w){
            return (int)(w/weight[0])*profit[0];
        }
        else
            return 0;
    }
    
    if(dp[ind][w]!=-1)
        return dp[ind][w];
    int notpick= helper(ind-1,w,profit,weight,dp);
    int pick=INT_MIN;
    if(weight[ind]<=w)
        pick=profit[ind]+helper(ind,w-weight[ind],profit,weight,dp);
    return dp[ind][w]=max(pick,notpick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return helper(n-1,w,profit,weight,dp);
}

/* Tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    //return helper(n-1,w,profit,weight,dp);
    for(int W=0;W<=w;W++){
        dp[0][W]= ((int)(W/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notpick= 0+dp[ind-1][W];
            int pick=0;
            if(weight[ind]<=W)
                pick=profit[ind]+dp[ind][W-weight[ind]];
            dp[ind][W]=max(pick,notpick);
        }
    }
    return dp[n-1][w];
}
*/

/*Space Optimization

 vector<int> prev(w+1,0),cur(w+1,0);
    for(int W=0;W<=w;W++){
        prev[W]= ((int)(W/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notpick= 0+prev[W];
            int pick=0;
            if(weight[ind]<=W)
                pick=profit[ind]+cur[W-weight[ind]];
            cur[W]=max(pick,notpick);
        }
        prev=cur;
    }
    return prev[w];
}
*/

/*
    vector<int> prev(w+1,0);
    for(int W=0;W<=w;W++){
        prev[W]= ((int)(W/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notpick= 0+prev[W];
            int pick=0;
            if(weight[ind]<=W)
                pick=profit[ind]+prev[W-weight[ind]];
            prev[W]=max(pick,notpick);
        }
        //prev=cur;
    }
    return prev[w];

*/
