#include <bits/stdc++.h> 
bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];
}
int findParent(int node, vector<int> &parent) {
    if (node== parent[node])
        return node;
    return parent[node] = findParent(parent[node],parent);
}
void findunion(int u, int v, vector<int> &parent, vector<int> &rank) {
       u = findParent(u,parent);
       v = findParent(v,parent);
       
       if(rank[u]>rank[v]) {
           parent[v] = u;
       } else if(rank[u]<rank[v]) {
           parent[u] = v;
       } else {
           parent[u] = v;
           rank[u]++;
       }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    sort(graph.begin(),graph.end(),comp);
    vector<int> parent(n+1,0) , rank(n+1,0);
    
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    int cost = 0;
    for(auto it: graph) {
         if(findParent(it[0],parent)!=findParent(it[1],parent)) {
               cost += it[2];
               findunion(it[0],it[1],parent,rank);
         }
    }
    return cost;
}