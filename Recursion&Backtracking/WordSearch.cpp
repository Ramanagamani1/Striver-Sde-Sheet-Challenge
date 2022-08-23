/*
Problem Statement
You are given a 2D board(N rows and M columns) of characters and a string “word”. Your task is to check if the given word exists in the grid or not. The word can be constructed from letters of sequentially adjacent cells, where “adjacent” cells are horizontally or vertically neighboring.
Note:
The same letter cell may not be used more than once.
For Example:
For a given word “design” and the given 2D board 
[[q’, ‘v’, ‘m’, ‘h’],
 [‘d’, ‘e’, ‘s’, ‘i’],
 [‘d’, ‘g’, ‘f’, ‘g’],
 [‘e’, ‘c’, ‘p’, ‘n’]]

The word design can be formed by sequentially adjacent cells as shown by the highlighted color in the 2nd row and last column.

Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
Then the T test cases follow.

The first line of each test contains a string word.

The second line of input contains two single space-separated integers 'N' and 'M' representing the number of rows and columns of the grid respectively.

The next 'N' lines contain 'M' single space-separated characters each representing the elements in a row of the matrix.
Output Format:
For each test case, print “true” or “false” in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 5
1 <= N <= 6
1 <= M <= 6
1 <= |word| <=20

Time Limit: 1 sec
Sample Input 1:
1
coding
4 4
c z k l
o d i a
r g n m
m r s d
Sample Output 1:
true
Explanation For Sample Input 1:
For the given word, and grid we can construct from letters of sequentially adjacent cells as shown below:

Sample Input 2:
2
ninjas
4 4
c d k s
o d s a
d g n j
e r i n
hello
2 3
h w e
e l o
Sample Output 2:
true
false */

bool search(int i,int j,vector<vector<char>> &board, string word,int k ,int n, int m) {
    if (k==word.size()) return true;
    if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]) return false;
    int ch=board[i][j];
    board[i][j]='#';
    bool opt1= search(i+1,j,board,word,k+1,n,m);
     bool opt2= search(i-1,j,board,word,k+1,n,m);
     bool opt3= search(i,j+1,board,word,k+1,n,m);
     bool opt4= search(i,j-1,board,word,k+1,n,m);
    board[i][j]=ch;
    
    return opt1 | opt2 | opt3 | opt4;
}
bool present(vector<vector<char>> &board, string word, int n, int m) 
{
    // Write your code here
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                if(search(i,j,board,word,0,n,m)==true)
                    return true;
            }
                
        }
    }
    return false;
}