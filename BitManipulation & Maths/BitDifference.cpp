int countBitsFlip(int a, int b){
        
        // Your logic here
        int count = 0;
        int res = a^b;
        
        while(res>0) {
            res = res & (res-1);
            count+=1;
        }
        return count;
    }