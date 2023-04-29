int findMin(int arr[], int n){
       int low = 0, high = n-1;
       
       
       while(low<=high) {
           
           int mid = low+(high-low)/2;
           
           if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]) {
               return arr[mid];
           }
           
           if(arr[mid]>arr[high]) {
               
               low = mid+1;
               
           } else
           
              high = mid-1;
       }
       return arr[low];
    }