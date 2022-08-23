int f(int i,int j,int n, int m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
	if(j<0 || j>=m)
		return -1e9+7;
	if(i==0){
		return matrix[0][j];
	}
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	int up=matrix[i][j]+f(i-1,j,n,m,matrix,dp);
	int ld=matrix[i][j]+f(i-1,j-1,n,m,matrix,dp);
	int rd=matrix[i][j]+f(i-1,j+1,n,m,matrix,dp);
	return dp[i][j]=max(up,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	int maxi=-1e9;
	for(int j=0;j<m;j++){
		maxi=max(maxi,f(n-1,j,n,m,matrix,dp));
	}
	return maxi;
    //  Write your code here.
}

/* Tabulation

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
            dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int l,r;
                if(j-1>=0)
                    l=matrix[i][j]+dp[i-1][j-1];
                else
                    l=1e9;
                if(j+1<m)
                    r= matrix[i][j]+dp[i-1][j+1];
                else
                    r=1e9;
                dp[i][j]=min(up,min(l,r));
          }
        }
        int mini=(int)1e9+7;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }

*/

/* Space Optimization

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
// 	vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<int> prev(m,0);
    for(int j=0;j<m;j++)
        prev[j]=matrix[0][j];
    for(int i=1;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            int up=matrix[i][j]+prev[j];
            int left,right;
            if(j-1>=0){
                left =matrix[i][j]+ prev[j-1];
            } else {
                left=  -1e9;
            }
            if(j+1<m){
                right =matrix[i][j]+ prev[j+1];
            } else {
                right=  -1e9;
            }
            cur[j]= max(up,max(left,right));
        }
        prev=cur;
    }
    
    int maxi=-1e9;
// 	for(int j=0;j<m;j++){
// 		maxi=max(maxi,f(n-1,j,n,m,matrix,dp));
// 	}
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
	return maxi;
    //  Write your code here.
}

*/