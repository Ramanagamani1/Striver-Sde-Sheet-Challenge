/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.*/

class Solution {
public:
   void helper(int i,int k,int n, int sumTillNow,vector<vector<int>> &ans, vector<int> &ds){
    if(sumTillNow>n) {
        return ;
    }
    
    if(k==0){
        if(sumTillNow==n){
            ans.push_back(ds);
            return;
        }
    }
    if(i==10){
        return ;
    }
    
    ds.push_back(i);
    sumTillNow+=i;
    helper(i+1,k-1,n,sumTillNow,ans,ds);
    ds.pop_back();
    sumTillNow-=i;
    //ignore
    helper(i+1,k,n,sumTillNow,ans,ds);
}
vector<vector<int>> combinationSum3(int k, int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    helper(1,k,n,0,ans,ds);
    return ans;
}

};