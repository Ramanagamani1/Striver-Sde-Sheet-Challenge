/* Using Priority Queue */
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S] = 0;
        pq.push({0,S});
        vector<int> ans;
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            for(auto it: adj[node]) {
                  int ndist = it[1];
                  int next = it[0];
                  
                  if(d+ndist < dist[next]) {
                      dist[next] = d+ndist;
                      pq.push({dist[next],next});
                  }
            }
        }
        for(int i=0;i<V;i++){
            ans.push_back(dist[i]);
        }
        return ans;
    }

/* Using set */

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    
    for(int i=0;i<edges;i++) {
          int u = vec[i][0];
          int v = vec[i][1];
          int w = vec[i][2];
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
    }
    
    set<pair<int,int>> st;
    vector<int> dist(vertices,INT_MAX);
    dist[source] = 0;
    st.insert({0,source});
    
    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        
        for(auto it: adj[node]) {
              int adjnode = it.first;
              int edgeWt = it.second;
            
              if(edgeWt+dis < dist[adjnode]) {
                  
                   if(dist[adjnode]!=1e9){
                       st.erase({dist[adjnode],adjnode});
                   }
                   dist[adjnode] = edgeWt + dis;
                   st.insert({dist[adjnode],adjnode});
              }
        }
    }
    return dist;
}
