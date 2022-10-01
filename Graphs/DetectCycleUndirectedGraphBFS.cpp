bool bfs(int node,vector<int> adj[],int vis[]) {
          vis[node] = 1;
          
          queue<pair<int,int>> q;
          q.push({node,-1});
          
          while(!q.empty()) {
              
              int n = q.front().first;
              int parent = q.front().second;
              q.pop();
              
              for(auto adjacentNode: adj[n]) {
                    if(!vis[adjacentNode]) {
                        q.push({adjacentNode,n});
                        vis[adjacentNode] = 1;
                    } 
                    else if(adjacentNode!=parent)
                      return true;
              }
          }
          return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(bfs(i,adj,vis))
                  return true;
            }
        }
        return false;
    }