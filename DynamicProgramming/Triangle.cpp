int f(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>& dp,int n) {
	if(i==n-1)
		return triangle[n-1][j];
	if(dp[i][j]!=-1)
		return dp[i][j];
	int down = triangle[i][j]+ f(i+1,j,triangle,dp,n);
	int dg = triangle[i][j]+ f(i+1,j+1,triangle,dp,n);
	return dp[i][j]=min(down,dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n,-1));
	return f(0,0,triangle,dp,n);
}

/* Tabulation 

 int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j]+dp[i+1][j];
                int dg = triangle[i][j]+dp[i+1][j+1];
                dp[i][j] = min(down,dg);
            }
        }
        return dp[0][0];
    }

*/

/* Space Optimization

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
// 	vector<vector<int>> dp(n,vector<int>(n,-1));
// 	return f(0,0,triangle,dp,n);
    vector<int> front(n,0);
    
    for(int j=0;j<n;j++){
        front[j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--) {
        vector<int> cur(n,0);
        for(int j=i;j>=0;j--) {
             int down=triangle[i][j]+front[j];
             int dg=triangle[i][j]+front[j+1];
             cur[j]=min(down,dg);
        }
       front=cur;
    }
    return front[0];
}



*/
