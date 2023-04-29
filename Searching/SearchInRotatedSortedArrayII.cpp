class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int N = arr.size();
        int low = 0, high = N-1;
        
        while(low<=high) {
            
            int mid = low+ (high-low)/2;
            
            if(arr[mid] == key) {
                
                return true;
            }

            if ((arr[mid] == arr[low]) && (arr[mid]==arr[high])) {
                
                low+=1;
                high-=1;
            }
          
            else if(arr[low]<=arr[mid]) {
                
                if(key>=arr[low] && key<=arr[mid]) {
                    
                    high = mid-1;
                } else {
                    
                    low = mid+1;
                }
            } else {
                
                if(key>=arr[mid] && key<=arr[high]) {
                     low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return false;
    }
    
};