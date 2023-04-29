int findZeroes(int arr[], int n, int m) {
        // code here
        int l=0,r=0,res = 0, zeros=0;
        
        while(r<n) {
            
            if(arr[r]==0){
                zeros+=1;
            }
            
            while(zeros>m) {
                if(arr[l]==0)
                  zeros-=1;
                 l+=1;
            }
            res = max(res,r-l+1);
            r+=1;
        }
        return res;
    }  