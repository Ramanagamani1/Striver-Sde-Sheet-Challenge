void dfs(int node,stack<int> &stk,vector<int> &vis,vector<int> adj[]) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it,stk,vis,adj);
            }
        }
        stk.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V,0);
	    stack<int> stk;
	    
	    for(int i=0;i<V;i++) {
	        if(!vis[i]) 
	        {
	            dfs(i,stk,vis,adj);
	        }
	    }
	    while(!stk.empty()) {
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans;
	}