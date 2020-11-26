const int MAX, pMAX;
int depth[MAX], parent[MAX][pMAX];
void init(){
    //TODO : make_tree : fill depth[i] & parent[i][0]
    //parent[i][j] = i의 1<<j번쨰 조상은?
    for(int j=1; j<pMAX; ++j)
	    for(int i=1; i<=n; ++i)
		    parent[i][j] = parent[parent[i][j-1]][j-1];
}
int LCA(int u, int v){
	if(depth[u] > depth[v]) swap(u,v);
	//v를 u의 높이까지 올린다
	int diff = depth[v] - depth[u];
	for(int i=0; i<pMAX; ++i){
		if(diff & (1<<i))
			v = parent[v][i];
	}
	if(u == v) return u;
	//부모가 다르면 올린다
	for(int i=pMAX-1; i>=0; --i)
		if(parent[u][i] != parent[v][i])
			u = parent[u][i], v = parent[v][i];
	return parent[u][0];
}