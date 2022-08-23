
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    m=m+n;
    int p1= m-n-1, p2=n-1;
    int i= m-1;
    while(p1>=0 && p2>=0) {
        if(arr1[p1]>arr2[p2]){
            arr1[i]=arr1[p1];
            p1-=1;
            i-=1;
        } else {
            arr1[i]=arr2[p2];
            i-=1;
            p2-=1;
        }
    }
    while(p2>=0){
        arr1[i]=arr2[p2];
        p2-=1;
        i-=1;
    }
    return arr1;
}

/*
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
   int p1=m-1,p2=n-1;
    int k=m+n-1;
    while(p2>=0) {
       if(p1>=0 && arr1[p1]>arr2[p2]){
            arr1[k]=arr1[p1];
            p1-=1;
            k-=1;
        } else {
            arr1[k]=arr2[p2];
            k-=1;
            p2-=1;
        } 
    }
    return arr1;

}*