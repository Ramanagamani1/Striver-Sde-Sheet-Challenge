#include <bits/stdc++.h> 
int f(int i,int n,vector<int>& arr, int k,vector<int> dp) {
        if(i==n) return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int len = 0, sum;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        
        for(int j=i;j<min(n,i+k); j++) {    
              len++;
              maxi=max(maxi,arr[j]);
              sum = (len*maxi) + f(j+1,n,arr,k,dp);
              maxans = max(sum,maxans);
        }
        return dp[i] = maxans;
    }
int maximumSubarray(vector<int> &arr, int k)
{
    // Write your code here.
     int n=arr.size();
        vector<int> dp(n+1,0);
        //return f(0,n,arr,k,dp);
    dp[n] = 0;
    for(int i=n-1;i>=0;i--) {
        int len = 0, sum;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        
        for(int j=i;j<min(n,i+k); j++) {    
              len++;
              maxi=max(maxi,arr[j]);
              sum = (len*maxi) + dp[j+1];
              maxans = max(sum,maxans);
        }
        dp[i] = maxans;
    }
    return dp[0];
}