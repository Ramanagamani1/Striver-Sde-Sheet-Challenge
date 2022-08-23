TC: 2*(N*M)
/* Set Matrix zeros

Problem Statement
Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0), then all the cells of the ith row and jth column should be changed to 0.
You must do it in place.
For Example:
If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0]
Input Format:
The first line of the input contains a single integer ‘T’ representing the no. of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’, denoting the no. of the rows and columns of the matrix.

The next 'N' lines will contain ‘M’ space separated integers representing the elements of the matrix.
Output Format:
For each test case, print the modified grid.

Print output of each test case in a separate line.
Note:
You are not required to print anything; it has already been taken care of. Just implement the function and return the answer.
Constraints:
1 ≤ T ≤ 1000
1 ≤ m, n ≤ 1000
Σ(m * n) ≤ 2000000
-2^(31) ≤ matrix[i][j] ≤ 2^(31)-1, for all (1 ≤ i ≤ n and 1 ≤ j ≤ m).

Time Limit: 1 sec
Follow up:
Can we do better than O(m * n) space?
Using O(m + n) space is an improvement but we can still do better.
We can do it using constant memory. Can you do it?
Sample Input 1 :
2
2 3
7 19 3
4 21 0
3 3
1 2 3
4 0 6
7 8 9
Sample Output 1 :
7 19 0
0 0 0
1 0 3
0 0 0
7 0 9
Explanation For Sample Input 1 :
For First Case - Similar to the example explained above. 

For Second Case - 
Only the cell (2,2) has zero. So all the elements of the second row and second column are changed to zeros.
*/

#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int r=matrix.size();
	int c=matrix[0].size();
	bool flag=false;
	for(int i=0;i<r;i++){
			if(matrix[i][0]==0) flag=true; // marking flag=true if any of the value in column 0 is 0.
			for(int j=1;j<c;j++){
				if(matrix[i][j]==0)
				matrix[i][0]=matrix[0][j]=0;
		}
	}
	for(int i=r-1;i>=0;i--){
		for(int j=c-1;j>=1;j--){
			if(matrix[i][0]==0 || matrix[0][j]==0)
				matrix[i][j]=0;
		}
		if(flag){
			matrix[i][0]=0; // marking the first column as 0 if flag=true
		}
	}
}