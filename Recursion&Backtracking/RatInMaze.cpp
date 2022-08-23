/*
ou are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.
Input Format:
The first line of input contains an integer 'N' representing the dimension of the maze.

The next 'N' lines of input contain 'N' space-separated integers representing the type of the cell.
Output Format :
For each test case, return the path from the start position to the destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= N <= 10
0 <= MAZE[i][j] <=1

Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

Time Limit: 1 sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation For Sample Output 1:
Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

So our path matrix will look like this:

1 0 0
1 0 0
1 1 1

Which is returned from left to right and then top to bottom in one line.*/\

#include<bits/stdc++.h>
void solve(vector<vector<int> > &maze,int i,int j,int n,vector<vector<int>> &ans,vector<vector<int>> &vis) {
    if(i==n-1 && j==n-1){
        vector<int> temp;
        vis[i][j]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n; j++) {
                temp.push_back(vis[i][j]);
            }
        }
        ans.push_back(temp);
        return ;
    }
    if(i<0 or j<0 or i>=n or j>=n or vis[i][j]==1 or maze[i][j]==0)
        return;
    vis[i][j]=1;
    solve(maze,i+1,j,n,ans,vis);
    solve(maze,i-1,j,n,ans,vis);
    solve(maze,i,j+1,n,ans,vis);
    solve(maze,i,j-1,n,ans,vis);
    vis[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(maze[0][0]==1)
    solve(maze,0,0,n,ans,vis);
    return ans;
}

or

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m, int n,vector<string> &ans,vector<vector<int>> 
    &vis,string move){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return ;
        }
        if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,m,n,ans,vis,move+'D');
            vis[i][j]=0;
        }
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,m,n,ans,vis,move+'L');
            vis[i][j]=0;
        }
        if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,m,n,ans,vis,move+'R');
            vis[i][j]=0;
        }
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,m,n,ans,vis,move+'U');
            vis[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
       vector<vector<int>> vis(n,vector<int>(n,0));
       if(m[0][0]==1)
         solve(0,0,m,n,ans,vis,"");
         return ans;
    }
};

    

