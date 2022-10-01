vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> safenodes;
        
        vector<int> adjRev[V];
        for(int i=0;i<V;i++) {
             for(auto it: adj[i]) {
                 // i->it change to it->i
                 adjRev[it].push_back(i);
             }
        }
        
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++) {
	        for(auto it: adjRev[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++) {
	        if(indegree[i]==0)
	         q.push(i);
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        safenodes.push_back(node);
	        
	        for(auto it:adjRev[node]) {
	             indegree[it]--;
	             
	             if(indegree[it]==0)
	               q.push(it);
	        }
	    }
	    sort(safenodes.begin(),safenodes.end());
	    return safenodes;

    }
};