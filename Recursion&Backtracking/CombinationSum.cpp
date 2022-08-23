/* Problem Statement
You are given an array/list ARR of N distinct positive integers. You are also given a non-negative integer B.
Your task is to find all unique combinations in the array whose sum is equal to B. A number can be chosen any number of times from array/list ARR.
Elements in each combination must be in non-decreasing order.
For example:
Let the array ARR be [1, 2, 3] and B = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)
Input Format
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

Then the first line of each test case contains two space separated integers  ‘N’ and ‘B’ denoting the number of elements in the array/list and the target sum respectively.

The second line of each test case contains N space separated integers the elements of array/list ARR.
Output Format :
For each test case, print all possible valid combinations in separate lines. You can print combinations in any order. Elements in each combination must be in non-decreasing order.

Output for each test case will be printed in a new line. 
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 15
1 <= B <= 20
1 <= ARR[i] <= 20

Time Limit: 1sec
Sample Input 1 :
2
3 8
2 3 5
1 2
1
Sample Output 1:
2 2 2 2
2 3 3 
3 5
1 1
Sample Input 2 :
1
3 5
1 2 3 
Sample Output 2:
1 1 1 1 1
1 1 1 2 
1 1 3
1 2 2
2 3 

TC: (2^t * k ) */

#include<bits/stdc++.h>
void helper(int i,vector<int>& arr,int sum,vector<int> &ds,
    vector<vector<int>> &ans) {
    if(i==arr.size()){
        if(sum==0)
            ans.push_back(ds);
        return;
    }
    if(arr[i]<=sum){
        ds.push_back(arr[i]);
        helper(i,arr,sum-arr[i],ds,ans);
        ds.pop_back();
    }
    
    helper(i+1,arr,sum,ds,ans);
}
vector<vector<int>> combSum(vector<int>& arr, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp;
    vector<vector<int>> ans;
    helper(0,arr,B,dp,ans);
    return ans;
}

