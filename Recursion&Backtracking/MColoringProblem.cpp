/* Problem Statement
You are given an undirected graph in the form of an adjacency matrix along with an integer M. You need to tell if you can color the vertices of the graph using at most M colors such that no two adjacent vertices are of the same color.
For Example:
If the given adjacency matrix is:
[0 1 0]
[1 0 1]
[0 1 0] and M = 3.
The given adjacency matrix tells us that 1 is connected to 2 and 2 is connected to 3. So if we color vertex 1 with 2, vertex 2 with 1, and vertex 3 with 2, it is possible to color the given graph with 2 colors: M.
Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
Then the T test cases follow.

The first line of the test case contains two space-separated integers V and M, denoting the number of vertices in the undirected graph and the number of colors respectively.

Each of the next V lines contains V integers denoting the adjacency matrix of the undirected graph.
Output Format:
For each test case, you need to return “YES” if we can color the given graph with at most M colors. Otherwise, return “NO”. (without the inverted commas)
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 ≤ T ≤ 1000
1 ≤ V ≤ 20
1 ≤ M ≤ V

Time Limit : 1 sec 
Sample Input 1:
3
3 3
0 1 0
1 0 1
0 1 0
3 1
0 1 0
1 0 1
0 1 0
2 1
0 1
1 0
Sample Output 1:
YES
NO
NO */

#include <bits/stdc++.h>
bool isValid(int node,vector<vector<int>> &mat,int col,int n,vector<int> &color){
    for(int k=0;k<n;k++){
        if(k!=node && mat[k][node]==1 && color[k]==col)
            return false;
    }
    return true;
}
bool solve(int node,vector<vector<int>> &mat, int m,int n,vector<int> &color) {
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(node,mat,i,n,color)){
            color[node]=i;
            if(solve(node+1,mat,m,n,color)==true)
                return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int> color(n,0);
    if(solve(0,mat,m,n,color)==true)
        return "YES";
    return "NO";
}