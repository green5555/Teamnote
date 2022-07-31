const int MAX = 0;
vector<pii> adj[MAX];
vector<int> bfs01(int start) {
	vector<int> dist(MAX, 1e9); dist[start] = 0;
	deque<int> q; q.push_back(start);
	while(!q.empty()) {
		int x = q.front(); q.pop_front();
		for(auto &[y, w] : adj[x]) {
			if(dist[y] > dist[x] + w) {
				dist[y] = dist[x] + w;
				if(w == 0) q.push_front(y);
				else q.push_back(y);
			}
		}
	}
	return dist;
}