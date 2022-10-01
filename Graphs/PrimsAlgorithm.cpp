#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++) {
         int u = g[i].first.first;
         int v = g[i].first.second;
         int w = g[i].second;
        
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }
    
    int key[n+1], mst[n+1], parent[n+1];
    for(int i=0;i<=n;i++) {
         key[i] = 1e9;
         mst[i] = false;
         parent[i] = -1;
    }
    key[1] = 0;
    parent[1] = -1;

    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //pq.push({0,1});
    vector<pair<pair<int, int>, int>> ans;

    for(int i=1;i<n;i++) {
          int mini=INT_MAX;
            int u;
            for(int v=1;v<=n;v++){
                if(mst[v]==false && key[v]<mini){
                    mini=key[v];
                    u=v;
                }
            }
          
          mst[u] = true;
        
          for(auto it:adj[u]) {
              int v = it.first;
              int w = it.second;
              
              if(mst[v]==false && w<key[v]) {
                  parent[v] = u;
                  //pq.push({key[v],v});
                  key[v] = w;
              }
          }
    }
   vector<pair<pair<int, int>, int> > result ; 
   for ( int i = 2 ; i <= n ; i++ ) 
   {
       result.push_back ( { {parent[i] , i} , key[i] } )  ;           
   }
       return result ; 
}
