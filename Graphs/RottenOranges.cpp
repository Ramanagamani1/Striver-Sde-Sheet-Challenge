int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        int time = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(t,time);
            for(int k=0;k<4;k++) {
                int nrow = r+dx[k];
                int ncol = c+dy[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1) {
                      q.push({{nrow,ncol},t+1});
                      vis[nrow][ncol] = 2;
                }
            }
            
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && vis[i][j]!=2) {
                    return -1;
                }
            }
        }
        return time;
    }