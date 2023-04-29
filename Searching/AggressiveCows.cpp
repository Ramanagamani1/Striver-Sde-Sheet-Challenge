class Solution {
public:

    bool cowsCanBePlaced(vector<int> &stalls,int n,int k,int dis) {
        
        int cows = 1;
        int pos = stalls[0];
        
        for(int i=1;i<n;i++) {
            
            if(stalls[i]-pos >= dis) {
                
                cows+=1;
                pos = stalls[i];
            } 
            if (cows == k) return true;
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int low = 1, high = stalls[n-1]-stalls[0];
        int res = 1;
        
        while(low<=high) {
            
            int mid = low+(high-low)/2;
            
            if(cowsCanBePlaced(stalls,n,k,mid)) {
                
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return res;
    }
};