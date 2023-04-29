vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    int n = s.length();
		    int size = 1<<n;
		    
		    for(int i=0;i<size;i++) {
		        string temp="";
		        for(int j=0;j<n;j++) {
		            if (i & (1<<j)) {
		                temp = temp+s[j];
		            }
		        }
		        if(temp!="")
		        res.push_back(temp);
		    }
		    sort(res.begin(),res.end());
		    return res;
		}