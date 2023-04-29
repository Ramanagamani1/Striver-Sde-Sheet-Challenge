int findOnce(int arr[], int n)
    {
        //code here.
        
        int low = 0, high = n-1;
        
        while(low<=high) {
            
            int mid = low+ (high-low)/2;
            
            if (mid%2==0) {
                
                if(arr[mid]!=arr[mid+1]) {
                    
                    high = mid-1;
                    
                } else {
                    
                    low = mid+1;
                }
            }
            else {
                
                if(arr[mid]!=arr[mid-1]) {
                    
                    high = mid-1;
                }
                else {
                    
                    low = mid+1;
                }
            }
        }
        return arr[low];
    }