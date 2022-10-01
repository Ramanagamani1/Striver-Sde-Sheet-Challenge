 void dfs(int node,int parent, vector<int> &vis,vector<int> &tin,vector<int> &low,int timer,vector<int> adj[],vector<vector<int>> &ans) {
         vis[node] = 1;
         tin[node] = low[node] = timer++;
         for(auto it: adj[node]) {
               if(it==parent)
                   continue;
               if(!vis[it]) {
                   dfs(it,node,vis,tin,low,timer,adj,ans);
                   low[node] = min(low[node],low[it]);
                   if(low[it]>tin[node]){
                       ans.push_back({node,it});
                   }
               } else {
                   low[node] = min(low[node],tin[it]);
               }
         }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> vis(n,0), tin(n,-1),low(n,-1);
        int timer = 0;
        vector<int> adj[n];
        int m = connections.size();
        for(int i=0;i<m;i++) {
             int u = connections[i][0];
             int v = connections[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(i,-1,vis,tin,low,timer,adj,ans);
            }
        }
        return ans;
    }