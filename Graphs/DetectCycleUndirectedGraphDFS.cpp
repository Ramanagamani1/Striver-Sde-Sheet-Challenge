bool dfs(int src,int parent,vector<int> adj[],int vis[]) {
        vis[src] = 1;
        for(auto it:adj[src]) {
            if(!vis[it]) {
                if(dfs(it,src,adj,vis)==true)
                  return true;
            } else if(it!=parent)
                  return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i,-1,adj,vis))
                  return true;
            }
        }
        return false;
    }