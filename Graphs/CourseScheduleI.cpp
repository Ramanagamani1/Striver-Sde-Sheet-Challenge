	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj[V];
        for(auto it: prerequisites){
            adj[it.first].push_back(it.second);
        }
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
	    
	    if(topo.size()==V) return true;
	    else return false;
	    
	}

/* dfs cycle detection in directed graph using one vis array

 bool dfs(int i,vector<int> &vis,vector<int> adj[]){
        if(vis[i]==2) return true;
         vis[i]=2;
        
         for(int j=0; j<adj[i].size(); j++){
              if(vis[adj[i][j]]==1) continue;
              if(dfs(adj[i][j],vis,adj)) return true;
         }
         
        vis[i] = 1;
        
        return false;
   }

    bool canFinish(int A, vector<vector<int>>& B) {
        vector<int> adj[A+1];
        vector<int> vis(A+1,0);
        if(B.size()==0)
            return true;
        for(int i=0;i<B.size();i++){
             adj[B[i][0]].push_back(B[i][1]);
        }
        for(int i=0;i<A;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj))
                   return false;
            }
        }
        return true;
    }

*/