#include<bits/stdc++.h>
int largestRectangle( vector<int> &height) {
    int n = height.size();
    stack<int> stk;
    int maxi = 0;
    for(int i=0;i<=n;i++) {
        while(!stk.empty() && (i==n || height[stk.top()]>=height[i])) {
            int h = height[stk.top()];
            stk.pop();
            int width;
            if(stk.empty()) 
                width = i;
            else
                width = i-stk.top()-1;
            maxi = max(maxi,width*h);
        }
        stk.push(i);
    }
    return maxi;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
    vector<int> height(m,0);
    int maxArea = 0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==1) height[j]++;
            else
                height[j]=0;
        }
        int area = largestRectangle(height);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}