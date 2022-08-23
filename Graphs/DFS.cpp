#include<bits/stdc++.h>
void dfsTraversal(int node,vector<int> adj[],vector<int> &vis,vector<int> &temp) {
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adj[node]){
          if(!vis[it]){
              dfsTraversal(it,adj,vis,temp);
          }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> dfs;
    vector<int> vis(V,0);
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfsTraversal(i,adj,vis,temp);
            dfs.push_back(temp);
        }
    }
    return dfs;
}//