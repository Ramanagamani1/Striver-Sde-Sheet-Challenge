#include<bits/stdc++.h>
bool checkPossible(string &s,string &t) {
    if(s.size()!=t.size()+1) return false;
    int first = 0,second=0;
    while(first<s.size()) {
        if(second<t.size() && s[first] == t[second]) {
            first++;
            second++;
        } else {
            first++;
        }
    }
    if(first == s.size() && second==t.size()) return true;
    return false;
}
bool comp(string &s,string &t) {
    return s.size() < t.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
        int n=arr.size();
        int maxi = 1;
        sort(arr.begin(),arr.end(),comp);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(arr[i],arr[prev]) && 1+dp[prev]>dp[i]) {
                     dp[i] = 1+dp[prev];
                }
            }
            if(dp[i]>maxi) {
                maxi = dp[i];
            }
        }
    return maxi;
}