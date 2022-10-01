class Solution {
public:
    void dfs(int node, vector<int> adj[],vector<int> &vis) {
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& edges) {
        int V=edges.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                if(edges[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]){
                count+=1;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};