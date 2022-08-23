/* Problem Statement
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.
Note: A substring is a contiguous segment of a string.
For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.
Input Format:
The only line of input contains a string 'S'.
Output Format :
For each test case, print all the possible palindromic partitions of the given string in a separate line.

Each substring of a partition is written within quotes(““) and separated by comma(,) and space, and each partition of the given string is written inside square brackets[].

The output of each test case will be printed in a separate line.
Note:
All the substrings of a partition are sorted in lexicographical order in the output. You just need to return the partitions in any order.

You do not need to print or sort anything, it has already been taken care of. Just implement the function.
Constraints :
0 <= |S|<= 15
where |S| denotes the length of string 'S'.

Time Limit: 1 sec.
Sample Input 1:
aaC
Sample Output 1:
["C", "a", "a"]
["C", "aa"]
Explanation For Input 1:
For the given string "aaC" there are two partitions in which all substring of partition is a palindrome. */

#include<bits/stdc++.h>
bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
void solve(int ind,string &s,vector<string> &temp,vector<vector<string>> &ans){
    if(ind==s.size()){
        ans.push_back(temp);
        return ;
    }
    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            temp.push_back(s.substr(ind,i-ind+1));
            solve(i+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> temp;
    solve(0,s,temp,ans);
    return ans;
}