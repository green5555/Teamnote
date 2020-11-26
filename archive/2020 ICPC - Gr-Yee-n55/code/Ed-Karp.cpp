//

const int MAX = 1000, INF = INT_MAX;
struct edge {
	int next, cap, flow = 0, rev_idx;
	edge() {}
	edge(int n, int c) : next(n), cap(c) {}
	int remain() {
		return cap - flow;
	}
};
vector<edge> adj[MAX];
void makeEdge(int u, int v, int c) {
	adj[u].emplace_back(v, c);
	adj[v].emplace_back(u, 0);
	adj[u].back().rev_idx = adj[v].size() - 1;
	adj[v].back().rev_idx = adj[u].size() - 1;
}
int parent[MAX];
pii path[MAX];
int solve(int S, int E) {
	int ans = 0;
	queue<int> q;
	while (1) {
		memset(parent, -1, sizeof(parent));
		q.push(S);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < adj[u].size(); ++i) {
				auto &e = adj[u][i];
				if (e.remain() > 0 && parent[e.next] == -1) {
					parent[e.next] = u;
					path[e.next] = { u, i };
					q.emplace(e.next);
				}
			}
		}
		if (parent[E] == -1) break;
		int ret = INF;
		for (int i = E; i != S; i = parent[i])
			ret = min(ret, adj[path[i].xx][path[i].yy].remain());
		for (int i = E; i != S; i = parent[i]) {
			auto &e = adj[path[i].xx][path[i].yy];
			e.flow += ret;
			adj[e.next][e.rev_idx].flow -= ret;
		}
		ans += ret;
	}
	return ans;
}