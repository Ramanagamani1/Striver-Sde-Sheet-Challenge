/*
Given a string S containing digits from 2 to 9 inclusive. Your task is to find all possible letter combinations that the number could represent.
A mapping from Digits to Letters (just like in Nokia 1100) is shown below. Note that 1 does not map to any letter.

Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

Then the 'T' test cases follow.

The first and only line of each test case contains string S.
Output Format
For each test case, the list containing all the combinations of letters will be printed.

The output of each test case is printed in a separate line.
Note
You don’t have to print anything, it has already been taken care of. Just implement the function.  

The output strings can be returned in any order.
Constraints:
1 <= T <= 10 
1 <= |S| <= 10 
2 <= S[i] <=9  

Where |S| is the length of string 'S" and 'S[i]' represents the element of the string S. 

Time Limit: 1 sec
Sample Input 1:
1 
23
Sample Output 1:
ad ae af bd be bf cd ce cf

The letters corresponding to 2 are ‘a’, ‘b’, ‘c’ and corresponding to 3 are ‘d’, ‘e’, ‘f’. All the possible letter combinations for “23” will be "ad","ae","af","bd","be","bf","cd","ce","cf".*/

#include<bits/stdc++.h>
void help(int i,string &s,string &temp,unordered_map<char,string> &m,vector<string> &ans){
    if(i==s.size()){
        ans.push_back(temp);
        return ;
    }
    string str = m[s[i]];
    for(int j=0;j<str.size();j++){
        temp.push_back(str[j]);
        help(i+1,s,temp,m,ans);
        temp.pop_back();
    }
}
vector<string> combinations(string s){
	
	// Write your code here
    vector<string> ans;
    string temp;
	unordered_map<char,string> mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    help(0,s,temp,mp,ans);
    return ans;
}
