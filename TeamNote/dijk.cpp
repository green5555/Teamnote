const int MAX, INF;
vector<int> dijkstra(int start, auto &adj){	
	vector<int> dist(MAX, INF);
	dist[start] = 0;
	priority_queue <pii,vector<pii>,greater<pii>> Q;
	Q.push({0,start});
	while(!Q.empty()){
		int cost = Q.top().first;
		int here = Q.top().second;
		Q.pop();
		if(cost > dist[here]) continue;
		for(auto &there : adj[here]){
			int newCost = cost + there.first;
			if(dist[there.second] > newCost){
				Q.push({newCost, there.second});
				dist[there.second] = newCost;
			}
		}
	}
	return dist;
}
