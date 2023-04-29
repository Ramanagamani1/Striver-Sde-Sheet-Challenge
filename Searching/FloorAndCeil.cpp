int findFloor(int arr[], int n, int x) {
    
    int low=0,high = n-1;
    int ans = -1;
    while(low<=high) {
        
        int mid= (low+high)/2;
        
        if(arr[mid]==x)
          return arr[mid];
        else if(arr[mid] < x) {
            
            ans = arr[mid];
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}
int findCeil(int arr[], int n, int x) {
    
    int low=0,high = n-1;
    int ans = -1;
    while(low<=high) {
        
        int mid= (low+high)/2;
        
        if(arr[mid]==x)
          return arr[mid];
        else if(arr[mid] > x) {
            
            ans = arr[mid];
            high = mid-1;
        } else {
           low = mid+1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
   
    sort(arr,arr+n);
    int floor = findFloor(arr,n,x);
    int ceil = findCeil(arr,n,x);
    
    return {floor,ceil};
}