#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
     
     unordered_map<long long, int> mp;

     int maxLen = 0;
     long long prefix = 0;

     for(int i=0;i<a.size();i++) {

         prefix += a[i];

         if(prefix == k) {
             maxLen = max(maxLen,i+1);
         }

         long long rem = prefix-k;

         if(mp.find(rem)!=mp.end()) {
              maxLen = max(maxLen, i-mp[rem]);
         }

         if(mp.find(prefix)==mp.end()){
             mp[prefix] = i;
         }
     }

     return maxLen;
}

//2 pointer approach

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    int maxLen = 0;
    long long sum = a[0];
    int left = 0, right = 0;
    int n = a.size();

    while(right<n) {
        while(left<=right && sum>k) {
            sum-=a[left];
            left++;
        }

        if(sum==k){
            maxLen= max(maxLen, right-left+1);
        }

        right++;
        if(right<n) sum+=a[right];
    }

    return maxLen;
}