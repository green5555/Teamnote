const int MAX; const ll INF;
vector<pll> adj[MAX]; //{vertex, weight}
void dijkstra(int start, vector<ll> &dist){
    dist = vector<ll>(MAX, INF);
    dist[start] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,start});
    while(!q.empty()){
    	auto [cost, u] = q.top(); q.pop();
        if(cost > dist[u]) continue;
        for(auto &[v, w] : adj[u]){ //{w,v}?
            ll ncost = cost + w;
            if(dist[v] > ncost){
                q.push({ncost, v});
                dist[v] = ncost;
            }
        }
    }
}
