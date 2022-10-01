void dfs(int row,int col,int n,int m,int row0,int col0, vector<pair<int,int>> &vec,int dx[],int dy[],vector<vector<int>> &vis,vector<vector<int>> &grid) {
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        for(int k=0;k<4;k++) {
            int nrow = row+dx[k];
            int ncol = col+dy[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1) {
                dfs(nrow,ncol,n,m,row0,col0,vec,dx,dy,vis,grid);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        
        set< vector<pair<int,int>> > st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int dx[] ={-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>> vec;
                    
                    dfs(i,j,n,m,i,j,vec,dx,dy,vis,grid);
                    
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
    }