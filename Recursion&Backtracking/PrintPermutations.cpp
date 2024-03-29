/* Problem Statement
You are given an input string 'S'. Your task is to find and return all possible permutations of the input string.
Note:
1. The input string may contain the same characters, so there will also be the same permutations.

2. The order of permutation does not matter.
Input Format:
The first and only line of input contains a string 'S' of alphabets in lower case characters.
Output Format:
Print all the permutations of the given string 'S' in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.    
Constraint:
0 <= |S| <= 8

Where |S| denotes the length of string 'S'.

Time limit: 1 sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
Explanation For Sample Output 1:
All the possible permutations for string "cba" will be "abc", "acb", "bac", "bca", "cab" and "cba".
Sample Input 2:
xyx
Sample Output 2:
xyx
xxy
yxx
yxx
xyx
xxy
Explanation For Sample Output 2:
All the possible permutations for string "xyx" will be "xyx", "xxy", "yxx", "yxx", "xyx" and "xxy". Here, all three permutations "xyx", "yxx", "xxy" are repeating twice but we need to print all the possible permutations and hence we are printing them twice.. */


#include<bits/stdc++.h>
void helper(int ind, string &s,vector<string> &ans) {
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[ind],s[i]);
        helper(ind+1,s,ans);
        swap(s[ind],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    helper(0,s,ans);
    sort(ans.begin(),ans.end());
    return ans;
}