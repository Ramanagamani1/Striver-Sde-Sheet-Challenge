long long int merge(long long arr[],long long temp[], int low,int mid,int high) {
        int i,j,k;
        long long int inv_count = 0;
        i=low;
        j=mid;
        k=low;
        
        while (i< (mid)  && j<=high) {
            if(arr[i]<=arr[j])
              temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                inv_count += (mid-i);
            }
        }
        
        while(i< (mid)) {
            temp[k++] = arr[i++];
        }
        while (j<=high) {
            temp[k++] = arr[j++];
        }
        
        for(int i=low;i<=high;i++)
           arr[i] = temp[i];
           
         return inv_count;
    }
    long long int mergeSort(long long arr[],long long temp[],int low,int high) {
        int mid;
        long long int inv_count = 0;
        
        if (high > low) {
            
            mid=(low+high)/2;
            
            inv_count += mergeSort(arr,temp,low,mid);
            inv_count += mergeSort(arr,temp,mid+1,high);
            
            inv_count += merge(arr,temp,low,mid+1,high);
        }
        
        return inv_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        
        long long int ans = mergeSort(arr,temp,0,N-1);
        return ans;
    }

