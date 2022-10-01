int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int count = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || j==0 || i==n-1 ||  j==m-1) {
                    if(grid[i][j]==1) {
                         q.push({i,j});
                         vis[i][j]=1;
                    }
                }
            }
        }
        int dx[]= {-1,0,1,0};
        int dy[]= {0,1,0,-1};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++) {
                  int nrow = row+dx[k];
                  int ncol = col+dy[k];
                  
                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]= 1;
                  }
            }
        }
        
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]==1)
                  count+=1;
            }
        }
        return count;
    }