//O(EV^2), 0-1 cap에서 min{O(EV^(2/3), O(E^(3/2))}
const int MAX;
struct Dinic {
    struct edg {int pos, cap, rev;};
    vector<edg> adj[MAX];
    void clear() { for (int i = 0; i < MAX; i++) adj[i].clear(); }
    void make_edge(int s, int e, int x) {
        adj[s].push_back({e, x, (int) adj[e].size()});
        adj[e].push_back({s, 0, (int) adj[s].size() - 1});
    }
    int dis[MAX], pnt[MAX];
    bool bfs(int src, int sink) {
        memset(dis, 0, sizeof(dis));
        memset(pnt, 0, sizeof(pnt));
        queue<int> que;
        que.push(src);
        dis[src] = 1;
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (auto &e : adj[x]) {
                if (e.cap > 0 && !dis[e.pos]) {
                    dis[e.pos] = dis[x] + 1;
                    que.push(e.pos);
                }
            }
        }
        return dis[sink] > 0;
    }
    int dfs(int x, int sink, int f) {
        if (x == sink) return f;
        for (; pnt[x] < adj[x].size(); pnt[x]++) {
            edg e = adj[x][pnt[x]];
            if (e.cap > 0 && dis[e.pos] == dis[x] + 1) {
                int w = dfs(e.pos, sink, min(f, e.cap));
                if (w) {
                    adj[x][pnt[x]].cap -= w;
                    adj[e.pos][e.rev].cap += w;
                    return w;
                }
            }
        }
        return 0;
    }
    ll maxflow(int src, int sink) {
        ll ret = 0;
        while (bfs(src, sink)) {
            int r;
            while ((r = dfs(src, sink, 2e9))) ret += r;
        }
        return ret;
    }
}f;
