vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        bool prime[N+1];
        for(int i=0;i<=N;i++){
            prime[i] = true;
        }
        for(int i=2;i*i<=N;i++) {
            if(prime[i]){
                for(int j=i*i;j<=N;j=j+i){
                    prime[j]=false;
                }
            }
        }
        vector<int> ans;
        for(int i=2;i<=N;i++){
            if(prime[i])
            ans.push_back(i);
        }
        return ans;
    }