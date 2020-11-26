const int MAX;//MAX = max(Asize,Bsize)
int n, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];
void bfs_bmatching() {
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        if (!used[i])  dist[i] = 0; Q.push(i);
        else dist[i] = MAX * 2 + 1;
    }
    while (!Q.empty()) {
        int a = Q.front(); Q.pop();
        for (int &b : adj[a]) {
            if (B[b] != -1 && dist[B[b]] == MAX * 2 + 1) {
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}
bool dfs_bmatching(int a) {
    for (int &b : adj[a]) {
        if (B[b] == -1 ||(dist[B[b]] == dist[a] + 1 && dfs_bmatching(B[b]))) {
            used[a] = true;
            A[a] = b; B[b] = a;
            return true;
        }
    }
    return false;
}
int Hopcroft_Karp() {
    int match = 0, flow;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    memset(dist, 0, sizeof(dist));
    memset(used, 0, sizeof(used));
    while (1) {
        bfs_bmatching();
        flow = 0;
        for (int i = 0; i < n; ++i)
            if (!used[i] && dfs_bmatching(i)) flow++;
        if (!flow) break;
        match += flow;
    }
    return match;
}

//tourist's O(VE) faster than hopcroft
const int MAX = 100;
vector<int> adj[MAX];
int iter, pa[MAX], pb[MAX], was[MAX];
bool dfs(int v) {
    was[v] = iter;
    for (int u : adj[v])
        if (pb[u] == -1) {
            pa[v] = u; pb[u] = v; return 1;
        }
    for (int u : adj[v])
        if (was[pb[u]] != iter && dfs(pb[u])) {
            pa[v] = u; pb[u] = v; return 1;
        }
    return 0;
}
int biMatch() {
    memset(pa, -1, sizeof(pa));
    memset(pb, -1, sizeof(pb));
    memset(was, 0, sizeof(was));
    iter = 0;
    int res = 0;
    while (true) {
        iter++;
        int add = 0;
        for (int i = 0; i < MAX; i++)
            if (pa[i] == -1 && dfs(i)) add++;
        if (!add) break;
        res += add;
    }
    return res;
}