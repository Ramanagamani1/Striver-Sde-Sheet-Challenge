bool check(int node,int V,vector<int> adj[], int vis[],int pathvis[]) {
        vis[node] = 1;
        pathvis[node] =1 ;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(check(it,V,adj,vis,pathvis)) return true;
            } else if(pathvis[it]==1) {
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathvis[V] = {0};
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(check(i,V,adj,vis,pathvis)) return true;
            }
        }
          
        return false;
    }