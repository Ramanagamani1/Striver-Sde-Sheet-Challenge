bool bfscheck(int start, int V, vector<int> &color,vector<int>adj[]) {
         color[start] = 0;
         queue<int> q;
         q.push(start);
         
         while(!q.empty()) {
             int node = q.front();
             q.pop();
             
             for(auto it:adj[node]) {
                   if(color[it]==-1){
                       color[it] = !color[node];
                       q.push(it);
                   } else if(color[it]==color[node]) {
                       return false;
                   }
             }
         }
         return true;
    }
    bool dfscheck(int start,int V, vector<int> &color,vector<int>adj[]) {
        for(auto it:adj[start]) {
            if(color[it]==-1) {
                color[it] = !color[start];
                if(!dfscheck(it,V,color,adj))
                    return false;
            } else if(color[it]==color[start]) {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	     vector<int> color(V,-1);
	     
	     for(int i=0;i<V;i++) {
	         if(color[i]==-1)
	         {
	             color[i] = 1;
	             if(!dfscheck(i,V,color,adj))
	              return false;
	         }
	     }
	     return true;
	}