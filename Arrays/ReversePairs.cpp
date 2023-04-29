#include <bits/stdc++.h> 
int merge(vector<int> &arr,int low,int mid,int high) {
    int inv = 0;
    int j = mid+1;
    
    for(int i=low;i<=mid;i++) {
         while(j<=high && arr[i] > 2*arr[j])
             j+=1;
        
        inv += (j-(mid+1));
    }
    vector<int> temp;
    int i=low;
    j=mid+1;
    while((i<=mid) && j<=high) {
        if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
        if(arr[i]>arr[j])
            temp.push_back(arr[j++]);
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=high)
        temp.push_back(arr[j++]);
    for(int i=low;i<=high;i++)
        arr[i] = temp[i-low];
    return inv;
    
}
int mergeSort(vector<int> &arr,int low,int high) {
    if(low>=high) return 0;
    int mid = (low+high)/2;
    
    int inv = mergeSort(arr,low,mid);
    inv+= mergeSort(arr,mid+1,high);
    inv+= merge(arr,low,mid,high);
    
    return inv;
}
int reversePairs(vector<int> &arr, int n){
	
    int ans = mergeSort(arr,0,n-1);
    return ans;
}