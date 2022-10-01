/*


*/
#include <bits/stdc++.h> 
bool isPalindrome(int i,int j,string temp) {
    while(i<j) {
        if(temp[i]!=temp[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string str, vector<int> &dp) {
    if(i==n) return 0; 
    if(dp[i]!=-1) return dp[i];
    int mini = INT_MAX;
    for(int j=i;j<n;j++) {
        if(isPalindrome(i,j,str)) {
            int cuts = 1+f(j+1,n,str,dp);
            mini = min(mini,cuts);
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n+1,-1);
    //return f(0,n,str,dp)-1;
    dp[n] = 0;
    for(int i=n-1;i>=0;i--) {
        int mini = INT_MAX;
        for(int j=i;j<n;j++) {
            if(isPalindrome(i,j,str)) {
                int cuts = 1+dp[j+1];
                mini = min(mini,cuts);
            }
        }
        dp[i] = mini;
    }
    return dp[0]-1;
}
