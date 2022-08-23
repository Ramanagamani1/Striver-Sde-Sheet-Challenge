/*

Problem Statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format:
The first and the only line of input contains an integer 'N' representing the size of the chessboard and the number of queens.
Output Format:
Each line would be representing a single configuration.

Each configuration would contain 'N '* 'N' elements printed row-wise separated by spaces. The position where we can place the queen will have the value 1 rest will have the value 0.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'N' <= 10

Time Limit: 1sec
Sample Input 1:
4
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
Sample Input 2:
3
Sample Output2:
      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty. */

bool isSafe(int row,int col,vector<vector<int>> &board,int n) {
    int r=row;
    int c=col;
    while(row>=0 && col>=0){
        if(board[row][col]==1) return false;
        row-=1;
        col-=1;
    }
    row=r;
    col=c;
    while(col>=0){
        if(board[row][col]==1) return false;
        col-=1;
    }
    row=r;
    col=c;
    while(row<n && col>=0){
        if(board[row][col]==1) return false;
        col-=1;
        row+=1;
    }
    return true;
}
void helper(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n) {
    if (col==n) {
        vector<int> temp;
        for(auto i: board) {
            for(auto j: i) {
                temp.push_back(j);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            helper(col+1,board,ans,n);
            board[row][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
     vector<vector<int>> ans;
     vector<vector<int>> board(n,vector<int>(n,0));
     helper(0,board,ans,n);
     return ans;  
}

/* or */

void helper(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal) {
    if (col==n) {
        vector<int> temp;
        for(auto i: board) {
            for(auto j: i) {
                temp.push_back(j);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0){
            board[row][col]=1;
            leftRow[row]=1;
            upperDiagonal[n-1+col-row]=1;
            lowerDiagonal[row+col]=1;
            helper(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
            board[row][col]=0;
            leftRow[row]=0;
            upperDiagonal[n-1+col-row]=0;
            lowerDiagonal[row+col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
     vector<vector<int>> ans;
     vector<vector<int>> board(n,vector<int>(n,0));
     vector<int> left(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
     helper(0,board,ans,n,left,upperDiagonal,lowerDiagonal);
     return ans;  
}