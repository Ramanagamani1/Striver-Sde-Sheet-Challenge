#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
     vector<int> ans;
     int num1=-1, num2=-1;
     int count1=0,count2=0;
     for(auto it: arr) {
         if(it==num1) count1+=1;
         else if(it==num2) count2+=1;
         else if(count1==0) {
             num1= it;
             count1=1;
         } else if(count2==0) {
             num2=it;
             count2=1;
         } else{
             count1-=1;
             count2-=1;
         }
     }
     count1=0,count2=0;
     for(int i=0;i<arr.size();i++) {
         if(arr[i]==num1)
             count1+=1;
         if(arr[i]==num2)
             count2+=1;
     }
     if(count1 > arr.size()/3)
         ans.push_back(num1);
      if(count2 > arr.size()/3)
         ans.push_back(num2);
    return ans;
}