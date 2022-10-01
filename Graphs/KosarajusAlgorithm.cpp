void topoSort(int node,stack<int> &st,vector<int> &vis,vector<int> adj[]){
	    vis[node]=1;
	    for(auto it: adj[node]) {
	        if(!vis[it]) {
	            topoSort(it,st,vis,adj);
	        }
	    }
	    st.push(node);
	}
	
	void dfs(int node,vector<int> &vis,vector<int> adj[]){
	    vis[node]=1;
	    for(auto it: adj[node]) {
	        if(!vis[it]) {
	            dfs(it,vis,adj);
	        }
	    }
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
              topoSort(i,st,vis,adj);
        }
        
        vector<int> transpose[V];
        for(int i=0;i<V;i++) {
            vis[i] = 0;
            for(auto it: adj[i]) 
            {
                transpose[it].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()) {
            int node= st.top();
            st.pop();
                  if(!vis[node]) {
                      dfs(node,vis,transpose);
                      count+=1;
                  }
        }
        return count;
        
    }