/*

You are given an array of string ‘arr’ of size ‘N’. Your task is to find the maximum possible length of string, with unique characters formed by the concatenation of sub-sequences of ‘arr’.
For Example:
Consider ‘arr’ = [‘cha’, ‘r’, ‘act’, ‘ers’], the strings formed with unique characters, [‘cha’, ‘r’, ‘act’, ‘ers’, ‘char’, ‘ract’, ‘chaers’, ‘acters’]. The string with maximum length is ‘chaers’ and ‘acters’ with length 6. Hence the answer is 6.
Input Format:
 The first line of input contains the integer ‘T’ representing the number of test cases.

The first line of each test case contains ‘N’ space-separated strings representing the element of the array.
Output Format:
For each test case, print a single integer representing the maximum length of the string of unique characters formed by the concatenation of sub-sequences of the array ‘arr’.

Print a separate line for each test case
Constraints:
1 <= T <= 10
1 <= N <= 26
1 <= |arr[i]| <= 26

arr[i] contains only lowercase letters.

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
cha r act ers
abcdefghijklmnopqrstuvwxyz
Sample Output 1:
6
26
Explanation:
For the first test case, arr = [‘cha’, ‘r’, ‘act’, ‘ers’], the strings formed with unique characters, [‘cha’, ‘r’, ‘act’, ‘ers’, ‘char’, ‘ract’, ‘chaers’, ‘acters’]. The string with maximum length is ‘chaers’ and ‘acters’ with length 6. Hence the answer is 6.

For the second test case, arr = [‘abcdefghijklmnopqrstuvwxyz’], there is only one string in the array, and the string contains unique characters. The length of the string is 26. Hence the answer is 26.
Sample Input 2:
2
abc def f
yy bkhwmpbiisbldzknpm
Sample Output 2:
6   
0 */

#include<bits/stdc++.h>
bool compare(vector<int> mp,string &s){
    vector<int> selfCheck(26,0);
    for(int i=0;i<s.size();i++){
        if(selfCheck[s[i]-'a']==1) return false;
         selfCheck[s[i]-'a']=1;
    }
    for(int i=0;i<s.size();i++){
        if(mp[s[i]-'a']==1) return false;
    }
    return true;
}
int helper(int i,vector<string> &arr,vector<int> &mp,int len){
    
    if(i==arr.size())
        return len;
    string curr=arr[i];
    if(!compare(mp,curr)) {
        return helper(i+1,arr,mp,len);
    }
    else {
        for(int j=0;j<curr.size();j++)
            mp[curr[j]-'a']=1;
        len+=curr.size();
        int l1=helper(i+1,arr,mp,len);
        
        //skip
        for(int j=0;j<curr.size();j++)
            mp[curr[j]-'a']=0;
        len-=curr.size();
        int l2=helper(i+1,arr,mp,len);
        
        return max(l1,l2);
    }
    
}
int stringConcatenation(vector<string> &arr)
{
    // Write your code here
    
    vector<int> mp(26,0);
    return helper(0,arr,mp,0);
}
