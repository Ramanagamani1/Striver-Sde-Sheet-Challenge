int f(int day, int idx,vector<vector<int>> &points, vector<vector<int>> &dp) {
	if(day == 0) {
		int maxi=0;
		for(int i=0;i<=2;i++) {
			if(i!=idx)
				maxi = max(maxi,points[0][i]);
		}
		 return maxi;
	}
	if(dp[day][idx]!=-1)
		return dp[day][idx];
	int maxi=0;
	for(int i=0;i<=2;i++) {
			if(i!=idx){
				int p = points[day][i] + f(day-1,i,points,dp);
		        maxi = max(maxi,p);
			}
		}
	return dp[day][idx] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<vector<int>> dp(n,vector<int>(4,-1));
	return f(n-1,3,points,dp);
}