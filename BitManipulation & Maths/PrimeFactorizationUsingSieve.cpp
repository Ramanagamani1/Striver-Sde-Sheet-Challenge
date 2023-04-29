vector<int> findPrimeFactors(int N) {

        int spf[N+1];
        for(int i=0;i<=N;i++){
              spf[i] = i;
        }
        for(int i=2;i*i<=N;i++) {
            if(spf[i]==i){
                for(int j=i*i;j<=N;j=j+i){
                    if(spf[j]==j)
                       spf[j]=i;
                }
            }
        }
        vector<int> res;
        while(N!=1){
            res.push_back(spf[N]);
            N = N/spf[N];
        }
        return res;
    }