//O(VEf), Average = O(Ef)
const int MAX = 0;
struct MCMF{
	struct edg{ int pos, cap, rev, cost; };
	vector<edg> adj[MAX];
	void clear(){
		for(int i=0; i<MAX; i++) adj[i].clear();
	}
	void make_edge(int from, int to, int weight, int cap){
		adj[from].push_back({to, weight, (int)adj[to].size(), cap});
		adj[to].push_back({from, 0, (int)adj[from].size()-1, -cap});
	}
	int dist[MAX], pa[MAX], pe[MAX];
	bool inque[MAX];
	int spfa(int src, int sink){
		memset(dist, 0x3f, sizeof(dist));
		memset(inque, 0, sizeof(inque));
		queue<int> que;
		dist[src] = 0;
		inque[src] = 1;
		que.push(src);
		bool ok = 0;
		while(!que.empty()){
			int x = que.front();
			que.pop();
			if(x == sink) ok = 1;
			inque[x] = 0;
			for(int i=0; i<adj[x].size(); i++){
				edg e = adj[x][i];
				if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
					dist[e.pos] = dist[x] + e.cost;
					pa[e.pos] = x;
					pe[e.pos] = i;
					if(!inque[e.pos]){
						inque[e.pos] = 1;
						que.push(e.pos);
					}
				}
			}
		}
		return ok;
	}
	pii match(int src, int sink){
		int mincost = 0, maxflow=0;
		while(spfa(src, sink)){
			int cap = 1e9;
			for(int pos = sink; pos != src; pos = pa[pos]){
				cap = min(cap, adj[pa[pos]][pe[pos]].cap);
			}
			mincost += dist[sink] * cap;
			maxflow += cap;
			for(int pos = sink; pos != src; pos = pa[pos]){
				int rev = adj[pa[pos]][pe[pos]].rev;
				adj[pa[pos]][pe[pos]].cap -= cap;
				adj[pos][rev].cap += cap;
			}
		}
		return {mincost, maxflow};
	}
}f;
