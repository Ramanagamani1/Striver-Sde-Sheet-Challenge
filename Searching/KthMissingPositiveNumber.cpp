class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
    int n = a.size();
      int low =0 , high = n-1;
      
      while(low<=high) {
          
          int mid = low + (high-low)/2;
          
          int missing = a[mid]-(mid+1);
          
          if(missing < k)
             low = mid+1;
          else {
              high = mid-1;
          }
      }
      return low+k;
    }
};