int findCeil(vector<int> &arr, int n, int x) {
    
    int low=0,high = n-1;
    int ans = -1;
    while(low<=high) {
        
        int mid= (low+high)/2;
        
        if(arr[mid]==x)
          return mid;
        else if(arr[mid] > x) {
            
            ans = mid;
            high = mid-1;
        } else {
           low = mid+1;
        }
    }
    if(ans == -1) {
        return n;
    }
    return ans;
}

    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        return findCeil(Arr,N,k);
    }
};