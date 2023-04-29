vector<int>AllPrimeFactors(int N) {
	    if(N<=1)
	      return {};
	    vector<int> ans;
	    
	    for(int i=2;i*i<=N;i++) {
	        int flag = 0;
	        while(N%i==0){
	            flag=1;
	            N=N/i;
	        }
	        if(flag)
	          ans.push_back(i);
	    }
	    if(N>1){
	        ans.push_back(N);
	    }
	    return ans;
	    
	}