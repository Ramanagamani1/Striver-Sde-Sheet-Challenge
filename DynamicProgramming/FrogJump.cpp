#include <bits/stdc++.h>
int minEnergy(int n, vector<int> &heights,vector<int> &dp){
	if(n==0)
		return 0;
    if(dp[n]!=-1)
		return dp[n];
	int left= minEnergy(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
	int right=INT_MAX;
	if(n>1)
	right= minEnergy(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
	return dp[n]=min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	vector<int> dp(n+1,-1);
	minEnergy(n-1,heights,dp);
	return dp[n-1];
}