long long maxProduct(vector<int> arr, int n) {
	   long long max_so_far = arr[0];
	   long long max_end_here = arr[0];
	   long long min_end_here = arr[0];
	   
	   for(int i=1;i<n;i++) {
	       long long temp = max((long long)arr[i],max(max_end_here*arr[i],min_end_here*arr[i]));
	       min_end_here = min((long long)arr[i],min(max_end_here*arr[i],min_end_here*arr[i]));
	       max_end_here = temp;
	       max_so_far= max(max_so_far,max_end_here);
 	   }
	   return max_so_far;
	}