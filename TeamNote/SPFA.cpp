bool SPFA(int n, int start){
    vector<ll> dist(n, 1e12);
    queue<int> Q;
    vector<bool> inQ(n, 0);
    vector<int> visit(n, 0);
    dist[start] = 0;
    Q.push(start);
    inQ[start] = true;
    ++visit[start];
    while(!Q.empty()){
        int here = Q.front();
        Q.pop(); inQ[here] = false;
        for(auto &P : adj[here]){
            ll there = P.first, newDist = dist[here] + P.second;
            if(newDist < dist[there]){
                dist[there] = newDist;
                if(!inQ[there]){
                    Q.push(there);
                    inQ[there] = true;
                    if(++visit[there] >= n+1) return false;
                }
            }
        }
    } return true;
}
