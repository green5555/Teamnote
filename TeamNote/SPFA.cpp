bool SPFA(int n, int start, vector<int> &dist){
    dist = vector<int>(n, INF);
    queue<int> Q;
    bool inQ[MAX] = {};
    int visit[MAX] = {};
    dist[start] = 0;
    Q.push(start);
    inQ[start] = true;
    ++visit[start];
    while(!Q.empty()){
        int here = Q.front();
        Q.pop(); inQ[here] = false;
        for(auto &P : adj[here]){
            int there = P.first, newDist = dist[here] + P.second;
            if(newDist < dist[there]){
                dist[there] = newDist;
                if(!inQ[there]){
                    Q.push(there);
                    inQ[there] = true;
                    if(++visit[there] >= n) return false;
                }
            }
        }
    } return true;
}
