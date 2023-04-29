int normalMaxSum(int arr[],int n) {
        int end_here= arr[0], max_so_far=arr[0];
        for(int i=1;i<n;i++) {
            end_here = max(arr[i],end_here+arr[i]);
            max_so_far = max(max_so_far,end_here);
        }
        return max_so_far;
    }
    int circularSubarraySum(int arr[], int num){
         int normal_sum = normalMaxSum(arr,num);
         if (normal_sum < 0)
            return normal_sum;
         
         int sum = 0;
         for(int i=0;i<num;i++) {
             sum += arr[i];
             arr[i] = -arr[i];
         }
         int max_circular = sum+normalMaxSum(arr,num);
         return max(normal_sum,max_circular);
    }