#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    int n=edges.size();
    vector<int> adj[vertex];
    for(int i=0;i<n;i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    vector<int> bfs;
    vector<int> vis(vertex,0);
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        sort(adj[i].begin(),adj[i].end());
        while(!q.empty()){
            int x=q.front();
            q.pop();
            bfs.push_back(x);
            for(auto it:adj[x]){
                  if(!vis[it]){
                      q.push(it);
                      vis[it]=1;
                    }
                 }
             }
        }
    }
    return bfs;
}