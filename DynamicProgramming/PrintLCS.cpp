int lcs(string s, string t)
{
	//Write your code here
//     int n=s.size();
//     int m=t.size();
//     vector<int> prev(m+1,0),cur(m+1,0);
    //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //for(int i=0;i<=n;i++) dp[i][0]=0;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
             if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } else {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //print longest common subsequence
    int i=n,j=m;
    string ans="";
    int len=dp[n][m];
    for(int k=0;k<len;k++)
        ans+='$';
    int index=len-1;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index-=1;
            i--,j--;
        } else if(dp[i-1][j]>dp[i][j-1]){
            i=i-1;
        } else
            j=j-1;
    }
    //cout<<ans;
    return dp[n][m];
    //return f(n,m,s,t,dp);
}