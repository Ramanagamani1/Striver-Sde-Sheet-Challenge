int findFirstOccurrence(int arr[], int n , int x ) {
     int low = 0,high=n-1;
     int ans = -1;
     while(low<=high) {
         
         int mid = (low+high)/2;
         
         if(arr[mid]==x) {
             
             ans = mid;
             high = mid-1;
         } else if (arr[mid] > x) {
             high = mid-1;
         } else {
             low = mid+1;
         }
         
     }
     return ans;
}

int findLastOccurrence(int arr[], int n , int x ) {
    int low = 0,high=n-1;
     int ans = -1;
     while(low<=high) {
         
         int mid = (low+high)/2;
         
         if(arr[mid]==x) {
             ans = mid;
             low = mid+1;
         } 
         else if (arr[mid] > x) {
             high = mid-1;
         } 
         else {
             low = mid+1;
         }
         
     }
     return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    
    int first = findFirstOccurrence(arr,n,x);
    int last = findLastOccurrence(arr,n,x) ;
    
    return {first,last};
}