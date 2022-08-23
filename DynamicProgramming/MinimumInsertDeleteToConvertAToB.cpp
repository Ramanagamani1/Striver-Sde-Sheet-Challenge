/* (Intuition = (len(s1)+len(s2)) - 2*longest common subsequence ) */

int lcs(int i, int j,string &s,string &t,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==t[j])
        dp[i][j]=1+lcs(i-1,j-1,s,t,dp);
    else
        dp[i][j]=max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
    return dp[i][j];
}
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n=str.size();
    int m=ptr.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int x=lcs(n-1,m-1,str,ptr,dp);
    return n+m-2*x;
}