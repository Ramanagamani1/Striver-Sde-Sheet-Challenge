#include<bits/stdc++.h>
int f(int i,int j,string &p, string &s, vector<vector<int>> &dp) {
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0) {
        for(int k=0;k<=i;k++){
            if(p[k]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(p[i]==s[j] || p[i]=='?')
       return dp[i][j]=f(i-1,j-1,p,s,dp);
    
    if(p[i]=='*'){
        return dp[i][j] = f(i-1,j,p,s,dp) || f(i,j-1,p,s,dp);
    } 
        
    return dp[i][j]=false;
}
bool wildcardMatching(string p, string s)
{
   // Write your code here.
    int n=p.length();
    int m=s.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,p,s,dp);
}

// Tabulation

bool wildcardMatching(string p, string s)
{
   // Write your code here.
    int n=p.length();
    int m=s.length();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    //return f(n-1,m-1,p,s,dp);
    dp[0][0] = true;
    for(int j=1;j<=m;j++){
          dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        bool f1=true;
         for(int k=1;k<=i;k++){
            if(p[k-1]!='*') f1=false;
        }
        dp[i][0]=f1;
    }  
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(p[i-1]==s[j-1] || p[i-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[i-1]=='*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}

// Space optimization

bool wildcardMatching(string p, string s)
{
   // Write your code here.
    int n=p.length();
    int m=s.length();
    vector<bool> prev(m+1,false),cur(m+1,false);
    prev[0] = true;
    for(int j=1;j<=m;j++){
          prev[j]=false;
    }
    
    for(int i=1;i<=n;i++){
        bool flag=true;
         for(int k=1;k<=i;k++){
            if(p[k-1]!='*') {
                flag=false;
               break;
            }
        }
        cur[0] = flag;
        for(int j=1;j<=m;j++) {
            if(p[i-1]==s[j-1] || p[i-1]=='?')
                cur[j] = prev[j-1];
            else if(p[i-1]=='*'){
                cur[j] = prev[j] || cur[j-1];
            }
            else cur[j]=false;
        }
        prev=cur;
    }
    return prev[m];
}
