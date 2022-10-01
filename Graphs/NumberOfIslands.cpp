void dfs(vector<vector<char>> &A, vector<vector<int>> &visited, int i,int j, int n, int m,vector<int> &rows,vector<int> &cols) {
      visited[i][j]=1;
      for(int k=0;k<8;k++){
          int x=i+rows[k];
          int y=j+cols[k];
          if(x>=0 && y>=0 && x<n && y<m && A[x][y]-'0'==1 && visited[x][y]==0){
               dfs(A,visited,x,y,n,m,rows,cols);
          }
      }
      return ;
  }
  
  void bfs(int i,int j,int n,int m,vector<vector<int>> &visited,vector<vector<char>>& A) {
      queue<pair<int,int>> q;
      visited[i][j]=1;
      q.push({i,j});
      
      while(!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          
          q.pop();
          
          for(int dx=-1;dx<=1;dx++) {
              for(int dy=-1;dy<=1;dy++) {
                    int row = dx+x;
                    int col = dy+y;
                    
                    if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 && A[row][col]-'0'==1){
                          q.push({row,col});
                          visited[row][col]=1;
                    }
              }
          }
      }
  }

    int numIslands(vector<vector<char>>& A) {
        // Code here
        int n=A.size();
        int m=A[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        vector<int> rows={-1,-1,0,1,1,1,0,-1};
        vector<int> cols={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]-'0'==1 && visited[i][j]==0){
                    //dfs(A,visited,i,j,n,m,rows,cols);
                    count+=1;
                    bfs(i,j,n,m,visited,A);
                }
            }
        }
        return count;
    }