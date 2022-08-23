#include<bits/stdc++.h>
int f(int ind,int prev,int arr[], int n,vector<vector<int>> &dp) {
    if(ind==n)
        return 0;
    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
    int nottake = f(ind+1,prev,arr,n,dp);
    int take = 0;
    if(prev==-1 || arr[ind]>arr[prev]){
        take = 1+f(ind+1,ind,arr,n,dp);
    }
    return dp[ind][prev+1] = max(take,nottake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}

// Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--) {
        for(int prev=ind-1;prev>=-1;prev--){
              int len = 0 + dp[ind+1][prev+1];
            if(prev==-1 || arr[ind]>arr[prev]) {
                len = max(len,1 + dp[ind+1][ind+1]);
            }
            dp[ind][prev+1]=len;
        }
    }
    return dp[0][-1 + 1];
}

// Space optimization
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--) {
        for(int prev=ind-1;prev>=-1;prev--){
              int len = 0 + next[prev+1];
            if(prev==-1 || arr[ind]>arr[prev]) {
                len = max(len,1 + next[ind+1]);
            }
            cur[prev+1]=len;
        }
        next=cur;
    }
    return next[-1 + 1];
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}

// Printint LIS
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n,1),hash(n);
    int maxi=1;
    int lastind =0;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && 1+dp[j]>dp[i]){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        if(dp[i]>maxi){
            maxi= dp[i];
            lastind=i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastind]);
    while(hash[lastind]!=lastind) {
        lastind = hash[lastind];
        temp.push_back(arr[lastind]);
    }
    reverse(temp.begin(),temp.end());
}

//Using Binary Search

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int len=1;
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++) {
         if(arr[i]>temp.back()) {
             temp.push_back(arr[i]);
             len++;
         } else {
            int ind = lower_bound(temp.begin(),temp.end(),arr[i])- temp.begin();
             temp[ind] = arr[i];
         }
    }
    return len;
}
