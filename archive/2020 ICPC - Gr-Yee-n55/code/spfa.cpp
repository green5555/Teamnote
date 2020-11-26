const int MAX; const ll INF;
vector<pll> adj[555]; //{정점, 가중치}
bool SPFA(int start, vector<ll> &dist){
    dist = vector<ll>(MAX, INF); dist[start] = 0; 
    queue<int> Q; bool inQ[MAX] = {}; int visit[MAX] = {};
    Q.push(start); inQ[start] = true; ++visit[start];
    while(!Q.empty()){
        int here = Q.front(); Q.pop(); inQ[here] = false;
        for(auto &P : adj[here]){
            ll there = P.first, newDist = dist[here] + P.second;
            if(newDist < dist[there]){
                dist[there] = newDist;
                if(!inQ[there]){
                    Q.push(there); inQ[there] = true;
                    if(++visit[there] >= n+1) return false;
                }
            }
        }
    } return true;
}