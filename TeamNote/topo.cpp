const int MAX;
int indegree[MAX], result[MAX];
vector<int> adj[MAX];
bool topological_sort(int n){
	queue<int> Q;
	for(int i=0; i<n; ++i)
		if(!indegree[i]) Q.push(i);
	for(int i=0; i<n; ++i){
		if(Q.empty()) return false;
		int here = Q.front();
		Q.pop();
		result[i] = here;
		for(int &there : adj[here])
			if(!(--indegree[there]))
				Q.push(there);
	}
	return true;
}