bool dfscheck(int node,vector<int> adj[],int vis[],int pathVis[],int check[]) {
        vis[node]=1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                if(dfscheck(it,adj,vis,pathVis,check)) return true;
            } else if(pathVis[it]==1) {
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        
        vector<int> safenodes;
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfscheck(i,adj,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++) {
            if(check[i]==1)
               safenodes.push_back(i);
        }
        
        return safenodes;
    }