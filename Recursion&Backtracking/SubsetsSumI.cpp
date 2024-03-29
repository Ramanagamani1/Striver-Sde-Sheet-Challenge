/* Problem Statement
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :
The order of subsets is not important. 

The order of elements in a particular subset should be in increasing order of the index.
Input Format
The first line of input contains an integer 'N', which denotes the size of the array.

The second line contains 'N' single-space separated integers representing the elements of the array.

The third line contains a single integer 'K', which denotes the integer to which the subsets should sum to.
Output Format:
For each test case, print single-space separated integers of a subset of 'ARR' having sum = 'K'. 

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'N' <= 16
- (10 ^ 6) <= ARR[i] <= (10 ^ 6)
- 16 * (10 ^ 6) <= 'K' <= 16 * (10 ^ 6)

Where ‘ARR[i]’ denotes the value for ‘ith’ element of the array ‘ARR’ and 'K' is the given sum.

Time Limit: 1 sec.
Sample Input 1:
3
2 4 6
6
Sample Output 1:
2 4
6
Explanation Of The Sample Input 1:
For the array'ARR' = {2, 4, 6}, we can have subsets {}, {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}. Out of these 8 subsets, {2, 4} and {6} sum to the given 'K' i.e. 6. 
Sample Input 2:
6 
5 -1 8 2 7 0
7
Sample Output 2:
-1 8 
-1 8 0 
5 2 
5 2 0 
7 
7 0  */


void subsets(int ind,vector<int> arr, int n, int k,vector<int>  &ds,vector<vector<int>> &ans) {
    if(ind==n){
        if(k==0){
            ans.push_back(ds);
        }
        return;
    }
           ds.push_back(arr[ind]);
            subsets(ind+1,arr,n,k-arr[ind],ds,ans);
            ds.pop_back();
   
  
    subsets(ind+1,arr,n,k,ds,ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    subsets(0,arr,n,k,ds,ans);
    return ans;
}