class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isFeasible(int A[],int pages,int students,int N) {
        int cnt= 1, sum= 0;
        for(int i=0;i<N;i++) {
            if(A[i] > pages) return false;
            if(sum+A[i] > pages) {
                 cnt+=1;
                 sum = A[i];
                 
            } else {
                sum+=A[i];
            }
            
        }
        return (cnt<=students);
    }
    int findPages(int A[], int N, int M) 
    {
        int sum = 0, mx = 0;
        if (M>N) return -1;
        for(int i=0;i<N;i++) {
            sum+=A[i];
            mx = max(mx,A[i]);
        }
        int low = mx, high = sum;
        int res = -1;
        while(low<=high) {
            
            int mid = (low+high)/2;
            
            if(isFeasible(A,mid,M,N)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
            
        }
        return res;
    }
};
