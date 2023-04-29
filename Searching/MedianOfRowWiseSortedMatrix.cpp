class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0;i<R;i++) {
            
            if(matrix[i][0]<mini) {
                mini = matrix[i][0];
            }
            if(matrix[i][C-1]>maxi) {
                maxi = matrix[i][C-1];
            }
        }
        
        int low = mini, high=maxi;
        int req = (R*C)/2;
        
        while(low<=high) {
            
            int mid = (low+high)/2;
            int cnt = 0;
            
            for(int i=0;i<R;i++){
                cnt+= upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(cnt <= req) {
                low = mid+1;
            } else
               high = mid-1;
        }
        return low;
    }
};