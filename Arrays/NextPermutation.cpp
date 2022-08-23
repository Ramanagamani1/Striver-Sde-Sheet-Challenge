/*Problem Statement
You have been given a permutation of ‘N’ integers. A sequence of ‘N’ integers is called a permutation if it contains all integers from 1 to ‘N’ exactly once. Your task is to rearrange the numbers and generate the lexicographically next greater permutation.
To determine which of the two permutations is lexicographically smaller, we compare their first elements of both permutations. If they are equal — compare the second, and so on. If we have two permutations X and Y, then X is lexicographically smaller if X[i] < Y[i], where ‘i’ is the first index in which the permutations X and Y differ.
For example, [2, 1, 3, 4] is lexicographically smaller than [2, 1, 4, 3].
Input Format:
The first line contains a single integer ‘T’ representing the number of test cases. 

The first line of each test case will contain an integer ‘N’ representing the length of the permutation.

The second line contains ‘N’ space-separated integers which are the elements of the permutation.
Output Format:
For each test case, print the elements of the lexicographically next greater permutation with a single space-separated. If lexicographically next greater permutation doesn’t exist, print the lexicographically smallest permutation.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything; It has already been taken care of.
Constraints:
1 <= T <= 50
1 <= N <= 10000
1 <= P[i] <= N

Time limit: 1 sec
Sample Input 1:
2
3
1 2 3
5
2 3 1 4 5
Sample Output 1:
1 3 2
2 3 1 5 4
Explanation Of Sample Input 1:
In the first test case, the lexicographically next greater permutation is [1, 3, 2].

In the second test case, the lexicographically next greater permutation is [2, 3, 1, 4, 5].
Sample Input 2:
2
2
1 2
3
3 1 2
Sample Output 2:
2 1
3 2 1
Explanation For Sample Input 2:
In the first test case, the lexicographically next greater permutation is [2, 1].

In the second test case, the lexicographically next greater permutation is [3, 2, 1].*/
=============================================
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
    int indx1=-1,indx2=-1;
    for(int i=n-2;i>=0;i--){
              if(nums[i]<nums[i+1]){
                  indx1=i; break;
              }
        }
     if(indx1<0){
         reverse(nums.begin(),nums.end());
     }
     else{
            for(int i=n-1;i>indx1;i--){
                if(nums[i]>nums[indx1]){
                    indx2=i;break;
                }
              }
            swap(nums[indx1],nums[indx2]);
            reverse(nums.begin()+indx1+1,nums.end());
       }
    return nums;
}