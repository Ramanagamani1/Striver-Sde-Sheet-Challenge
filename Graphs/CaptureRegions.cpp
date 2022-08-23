#include<bits/stdc++.h>
void dfs(int i,int j,vector<vector<char>> &s, int n, int m,vector<int> &rows,vector<int> &cols) {
    s[i][j]='N';
    for(int k=0;k<4;k++){
        int x= i+rows[k];
        int y= j+cols[k];
        if(x>=0 && y>=0 && x<n && y<m && s[x][y]=='O'){
            dfs(x,y,s,n,m,rows,cols);
        }
    }
}
vector<vector<char>> captureRegion(vector<vector<char>> &s, int n, int m) 
{
    // Write your code here.
     vector<int> rows={0,0,1,-1};
    vector<int> cols={1,-1,0,0};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(s[i][j]=='O'){
                    dfs(i,j,s,n,m,rows,cols);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='O')
                s[i][j]='X';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='N')
                s[i][j]='O';
        }
    }
    return s;
}