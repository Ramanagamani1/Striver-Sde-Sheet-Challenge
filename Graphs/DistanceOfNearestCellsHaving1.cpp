vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<m;j++) {
	            
	            if(grid[i][j]==1) {
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    int dx[]={-1,0,1,0};
	    int dy[]={0,1,0,-1};
	    while(!q.empty()) {
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        dist[x][y] = steps;
	        
	        for(int k=0;k<4;k++) {
	            int nrow = x+dx[k];
	            int ncol = y+dy[k];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==0) {
	                  q.push({{nrow,ncol},steps+1});
	                  vis[nrow][ncol] = 1;
	            }
	        }
	        
	    }
	    return dist;
	}
};