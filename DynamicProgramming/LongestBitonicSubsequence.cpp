#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	 
     vector<int> dpl(n,1);
     vector<int> dpr(n,1);
     for(int i=1;i<n;i++) {
         for(int prev=0;prev<i;prev++) {
             if(arr[i]>arr[prev] && 1+dpl[prev]>dpl[i]) {
                 dpl[i]=1+dpl[prev];
             }
         }
     }
     for(int i=n-1;i>=0;i--) {
         for(int prev=n-1;prev>i;prev--) {
             if(arr[i]>arr[prev] && 1+dpr[prev]>dpr[i]) {
                 dpr[i]=1+dpr[prev];
             }
         }
     }
     int maxi=0;
     for(int i=0;i<n;i++) {
           maxi=max(maxi, dpl[i]+dpr[i]-1);
     }
    return maxi;
} 
