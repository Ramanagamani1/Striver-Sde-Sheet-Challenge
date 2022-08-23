/* Problem Statement
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
Input Format:
The first line contains a single integer 'T' denoting the number of test cases.
Then 'T' test cases follow.

Every test case contains 9 lines, with each line containing 9 single space-separated digits (0, if the cell is empty or a digit (1 - 9) otherwise).
Output Format:
For each test case, print a single line containing “yes”(without quotes), if there exists a Sudoku solution or “no” (without quotes) otherwise. Note the lowercase format of the output.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 5
N = 9
0 <= MATRIX[i][j] <= 9

Where 'N' denotes the size of the given square matrix.

Time Limit: 1sec
Sample Input 1:
1
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
yes

*/

bool isValid(int r,int c,int n,int matrix[9][9]){
    for(int k=0;k<9;k++) {
        if(matrix[r][k]==n) return false;
        if(matrix[k][c]==n) return false;
        
        if(matrix[3*(r/3)+k/3][3*(c/3)+k%3]==n)
            return false;
    }
    return true;
}

bool solve(int matrix[9][9]) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) {
            if(matrix[i][j]==0) {
                for(int n=1;n<=9;n++){
                    if(isValid(i,j,n,matrix)){
                        matrix[i][j]=n;
                        if(solve(matrix)==true)
                            return true;
                        else
                            matrix[i][j]=0;
                    }
                }
                 return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}
