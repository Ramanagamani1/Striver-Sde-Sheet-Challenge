#include <bits/stdc++.h>
int f(int i,int j,string s,string t,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==t[j]){
        dp[i][j]=1+f(i-1,j-1,s,t,dp);
    } else
        dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    return dp[i][j];
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(n-1,n-1,s,t,dp);
}

// use concept of longest common subsequence