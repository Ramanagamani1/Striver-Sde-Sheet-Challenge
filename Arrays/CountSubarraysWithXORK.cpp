#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int xorr = 0,count = 0;
    unordered_map<int,int> mp;
    
    for(auto it: arr) {
        xorr = xorr^it;
        if (xorr == x) {
            count+=1;
        }
        if (mp.find(xorr^x)!=mp.end()) {
            count+= mp[xorr^x];
        } 
        if(mp.find(xorr)!=mp.end()){
            mp[xorr] += 1;
        } else {
            mp[xorr] = 1;
        }
          
    }
    return count;
}