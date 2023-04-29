int findKRotation(int arr[], int n) {
	    // code here
	    
	    int low = 0, high = n-1;
	    
	    while(low<=high) {
	        
	        int mid = low+(high-low)/2;
	        
	        if (mid>low && mid<high && arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid])
	           return mid;
	           
	         if(arr[mid]>arr[high]) {
	             
	             low = mid+1;
	         }
	         else {
	             high = mid-1;
	         }
	    }
	    return low;
	}