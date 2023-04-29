#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char,int> mp;
    
    int p1=0,p2=0,len = 0;
    while(p2<input.size()) {
        if(mp.find(input[p2])!=mp.end()) {
            p1 = max(mp[input[p2]]+1,p1);
        }
            mp[input[p2]] = p2;
            len = max(len,p2-p1+1);
        p2+=1;
    }
    return len;
}

/*

int lengthOfLongestSubstring(string s) {
        int mx=1;
        unordered_set<char> mp;
        int p1=0,p2=1;
        int n=s.length();
        if(s=="")
            return 0;
        mp.insert(s[p1]);
        while(p2<n){
             if(mp.find(s[p2])==mp.end()){
                 mp.insert(s[p2]);
                 p2+=1;
                 mx=max(mx,p2-p1);
             }
            else{
                mp.erase(s[p1]);
                p1+=1;
            }
        }
        return mx;
    }

*/