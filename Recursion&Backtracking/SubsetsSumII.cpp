/* Problem Statement
Ninja is observing an array of ‘N’ numbers and wants to make as many unique subsets as possible. Can you help the Ninja to find all the unique subsets?
Note: Two subsets are called same if they have same set of elements.For example {3,4,1} and {1,4,3} are not unique subsets.
You are given an array ‘ARR’ having N elements. Your task is to print all unique subsets.
For Example
For the given if ARR = [1,1,3],the answer will be [ ],[1],[1,1],[1,3],[3],[1,1,3].
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer ‘N’ denoting the number of elements.
The second line of each test case contains ‘ARR’ array.
Output Format:
For each test case, print all the subsets in each line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Return the output in sorted format as shown in the sample output.
Constraints:
1 <= T <= 10
1 <= N <= 20.
1 <= ARR[i] <=100

Time limit: 1 sec
Sample Input 1:
2
3
1 1 3
4
1 3 3 3
Sample Output 1:
1
1 1
1 3
3
1 1 3

1
1 3
1 3 3
1 3 3 3 
3 
3 3
3 3 3
Explanation Of Sample Input 1:
For the first test case,
The unique subsets will be  [ ],[1],[1,1],[1,3],[3],[1,1,3]. 

For the second test case:
The unique subsets will be  [ ],[1,3],[1,3,3],[1,3,3,3],[3],[3,3],[3,3,3]. 
Sample Input 2:
2
4
5 5 3 5 
3
1 3 5 
Sample Output 2:
3 
3 5 
3 5 5 
3 5 5 5 
5 
5 5 
5 5 5 

1 
1 3 
1 3 5 
1 5 
3 
3 5 
5 */

#include<bits/stdc++.h>
void helper(int i,int n, vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans) {
    if(i==n){
        ans.push_back(ds);
        return ;
    }
    ds.push_back(arr[i]);
    helper(i+1,n,arr,ds,ans);
    ds.pop_back();
    // for skipping the future elements which are equal
    while(i+1<n && arr[i]==arr[i+1])
        i++;
    helper(i+1,n,arr,ds,ans);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    helper(0,n,arr,ds,ans);
    sort(ans.begin(),ans.end());
    return ans;
}