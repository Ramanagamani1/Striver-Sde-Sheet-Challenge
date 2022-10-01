void dfs(int sr,int sc,vector<vector<int>>& dp,vector<vector<int>>& image,int newColor, int initColor,int dx[],int dy[]) {
        dp[sr][sc] = newColor;
        for(int i=0;i<4;i++) {
            int x = sr+dx[i];
            int y = sc+dy[i];
            
            if(x>=0 && x<dp.size() && y>=0 && y<dp[0].size() && image[x][y]==initColor && dp[x][y]!=newColor){
                  dfs(x,y,dp,image,newColor,initColor,dx,dy);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int initColor = image[sr][sc];
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j] = image[i][j];
            }
        }
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        dfs(sr,sc,dp,image,newColor,initColor, dx,dy);
        return dp;
    }