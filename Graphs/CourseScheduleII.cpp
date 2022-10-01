vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        int V=n;
        vector<int> topo;
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++) {
	        for(auto it: adj[i]) {
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
	        topo.push_back(node);
	        
	        for(auto it:adj[node]) {
	             indegree[it]--;
	             
	             if(indegree[it]==0)
	               q.push(it);
	        }
	    }
	    if(topo.size()==V)
	    return topo;
	    else return {};
    }