int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int platforms = 1;
        int res = 1;
        
        int i=1,j=0;
        while(i<n && j<n) {
            if(arr[i]>dep[j]) {
                platforms--;
                j++;
            } else if(arr[i] <= dep[j]) {
                platforms++;
                i++;
            }
            if(platforms > res)
              res = platforms;
        }
        return res;
}