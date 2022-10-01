int find(int A[],int X)
{
   
    if(X==A[X]) return X;
    return find(A,A[X]);
       
}
void unionSet(int A[],int X,int Z)
{
	int x = find(A,X);
	int z = find(A,Z);
	
	A[x] = z;
}

/*
int parent[100];
int rank[100];

int makeSet(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node) {
    if(node == parent[node])
       return node;
    return parent[node] = findParent(parent[node]);
}

void union(int u,int v) {
    u = findParent(u);
    v = findParent(v);
    
    if(rank[u]<rank[v]){
        parent[u] = v;
    } else if(rank[u]>rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        rank[u]++;
    }
}


 */
