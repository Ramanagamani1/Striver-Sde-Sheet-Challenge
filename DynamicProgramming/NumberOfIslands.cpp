#include <bits/stdc++.h>
//TC : O(r*c) sc: O(r*c)+stack space
void dfs(int **a, vector<vector<int>> &visited, int i,int j, int n, int m,vector<int> &rows,vector<int> &cols) {
    visited[i][j]=1;
    for(int k=0;k<8;k++){
         int x=rows[k]+i;
        int y=cols[k]+j;
        if(x>=0 && x<n && y>=0 && y<m && a[x][y]==1 && visited[x][y]==0){
            dfs(a,visited,x,y,n,m,rows,cols);
        }
    }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    vector<vector<int>> visited(n,vector<int>(m,0));
    int count=0;
    vector<int> rows={-1,-1,0,1,1,1,0,-1};
    vector<int> cols={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && visited[i][j]==0){
                dfs(arr,visited,i,j,n,m,rows,cols);
                count+=1;
            }
        }
    }
    return count;
}
