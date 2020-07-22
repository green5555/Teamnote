const int MAX; const ll INF;
vector<pll> adj[MAX];
void dijkstra(int start, vector<ll> &dist){
    dist = vector<ll>(MAX, INF);
    dist[start] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> Q;
    Q.push({0,start});
    while(!Q.empty()){
        ll cost = Q.top().xx, here = Q.top().yy;
        Q.pop();
        if(cost > dist[here]) continue;
        for(auto &there : adj[here]){
            ll newCost = cost + there.xx;
            if(dist[there.yy] > newCost){
                Q.push({newCost, there.yy});
                dist[there.yy] = newCost;
            }
        }
    }
}
