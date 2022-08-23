/*You are given an array ‘Arr’ of ‘N’ positive integers. You are also given a positive integer ‘target’.
Your task is to find all unique combinations of the array ‘Arr’ whose sum is equal to ‘target’. Each number in ‘Arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.
Note:
In lexicographical order, combination/array  ‘A’  comes before array ‘B’ if ‘A’ is the prefix of array ‘B’, or if none of them is a prefix of the other and at the first position where they differ integer in ‘A’ is smaller than the integer in ‘B’.
Example:
Let the array ‘Arr’ be [1, 2, 3, 1] and ‘target’ = 5. Then all possible valid combinations in lexicographical order are -:
(1, 1, 3)
(2, 3)
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

Then the first line of each test case contains two space-separated integers  ‘N’ and ‘target’ denoting the number of elements in ‘Arr’ and the ‘target'

The second line of each test case contains N space-separated integers the elements of array ‘Arr’.
Output Format:
For each test case, print all possible valid combinations in a separate line in the lexicographical order. Elements in each combination must be in non-decreasing order. Print a new line after each test case.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10 
1 <= N <= 20
1 <= Arr[i] <= 30
1 <= target <= 30

Time Limit: 1 sec
Sample Input 1:
2
7 8
10 1 2 7 6 1 5
5 2
1 1 1 1 1
Sample Output 1:
1 1 6
1 2 5
1 7
2 6

1 1
Explanation For Sample Input 1:
Test Case 1:

Here ‘N’ = 7, Arr = [10, 1, 2, 7, 6, 1 , 5], and ‘target’ = 8
All unique combinations whose sum of elements is 8 are -:     

(1, 1, 6)  because, 1 + 1 + 6 = 8
(1, 2, 5)  because,  1 + 2 + 5 = 8
(1, 7)  because, 1 + 7 = 8                                                                                                               
(2, 6)  because,  2 + 6 = 8

Note, elements in each combination are in non-decreasing order and all unique combinations are arranged in lexicographical order. 

Test Case 2:

All elements are 1 in a given array and ‘target’ = 2,  so the only possible combination is (1, 1) as 1 + 1 = 2
Sample Input 2:
2
5 5
1 2 3 1 5
1 3
3
Sample Output 2:
1 1 3
2 3
5

3  */

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
        helper(i+1,arr,sum-arr[i],ds,ans);
        ds.pop_back();
    }
    // for skipping the future elements which are equal
    while(i+1<arr.size() && arr[i]==arr[i+1])
        i++;
    helper(i+1,arr,sum,ds,ans);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<int> dp;
    vector<vector<int>> ans;
    helper(0,arr,target,dp,ans);
    return ans;
}

/* or */

   void findCombinations(int ind,int target,vector<int>& arr,vector<vector<int>> &ans,vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
            return ;
        }
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target)
                break;
            ds.push_back(arr[i]);
            findCombinations(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findCombinations(0,target,candidates,ans,ds);
        return ans;
    }
};