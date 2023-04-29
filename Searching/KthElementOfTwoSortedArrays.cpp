int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n) {
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low = max(0,k-m), high  = min(k,n);
        
        while(low<=high) {
            
            int cut1 = low+(high-low)/2;
            
            int cut2 = k-cut1;
            
            int max1 = cut1==0? INT_MIN : arr1[cut1-1];
            int max2 = cut2==0? INT_MIN : arr2[cut2-1];
            
            int min1 = cut1==n? INT_MAX : arr1[cut1];
            int min2 = cut2==m? INT_MAX : arr2[cut2];
            
            if(max1<=min2 && max2<=min1) {
                
                return max(max1,max2);
                
            } else if(max1>min2) {
                
                high = cut1-1;
            } 
            else {
                
                low = cut1+1;
            }
        }
        return 1;
    }