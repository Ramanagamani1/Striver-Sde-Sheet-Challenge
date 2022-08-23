#include<bits/stdc++.h>
int f(int i,int j, string s,string t,vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i]==t[j]){
        dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    } else {
        dp[i][j] = f(i-1,j,s,t,dp);
    }
    return dp[i][j];
}
int numDistinct(string S, string T) {
    // Write your code here
    int n=S.length();
    int m= T.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n-1,m-1,S,T,dp);
}

// Tabultaion

int n=S.length();
    int m= T.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
     for(int i=0;i<=n;i++){
         dp[i][0]=1;
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(S[i-1]==T[j-1])
               dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
             else
               dp[i][j]=dp[i-1][j];
         }
     }
    return dp[n][m];

//Space Optimization

int numDistinct(string S, string T) {
    // Write your code here
    int n=S.length();
    int m= T.length();
    vector<int> prev(n+1,0), cur(m+1,0);
    
     prev[0]=1;
     cur[0]=1;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(S[i-1]==T[j-1])
               cur[j]=(prev[j-1]+prev[j]);
             else
               cur[j]=prev[j];
         }
         prev=cur;
     }
    return prev[m];
}

// 1D array
