#include<bits/stdc++.h>
int f(int i,int j,string &s, string &t, vector<vector<int>> &dp) {
     if(i<0) return j+1;
     if(j<0) return i+1;
     if(dp[i][j]!=-1)
         return dp[i][j];
    if(s[i]==t[j])
        dp[i][j]=f(i-1,j-1,s,t,dp);
    else
        dp[i][j] = 1+ min(f(i-1,j-1,s,t,dp),min(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)));
    return dp[i][j];
 }
int editDistance(string s1, string s2)
{
    //write you code here
    int n= s1.length();
    int m= s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n-1,m-1,s1,s2,dp);
}

// Tabulation

int editDistance(string s1, string s2)
{
    //write you code here
    int n= s1.length();
    int m= s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //return f(n-1,m-1,s1,s2,dp);
    for(int i=0;i<=n;i++)
          dp[i][0]=i;
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    }
    return dp[n][m];
}

// Space Optimization

int editDistance(string s1, string s2)
{
    //write you code here
    int n= s1.length();
    int m= s2.length();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++)
        prev[j]=j;
    for(int i=1;i<=n;i++) {
        cur[0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                cur[j]=prev[j-1];
            else
                cur[j]=1+min(prev[j-1],min(cur[j-1],prev[j]));
        }
        prev=cur;
    }
    return prev[m];
}
