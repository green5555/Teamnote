const int MAX; //MAX = max(Asize,Bsize)
struct BiMatching {
    int A[MAX], B[MAX], dist[MAX];
    bool used[MAX];
    vector<int> adj[MAX];
    int idx[MAX];
    void bfs_bmatching() {
        queue<int> Q;
        for (int i = 0; i < MAX; ++i) {
            if (!used[i]) {
                dist[i] = 0;
                Q.push(i);
            } else dist[i] = MAX * 2 + 1;
        }
        while (!Q.empty()) {
            int a = Q.front();
            Q.pop();
            for (int &b : adj[a]) {
                if (B[b] != -1 && dist[B[b]] == MAX * 2 + 1) {
                    dist[B[b]] = dist[a] + 1;
                    Q.push(B[b]);
                }
            }
        }
    }
    bool dfs_bmatching(int a) {
        for(int &i=idx[a]; i<adj[a].size(); ++i){
            int b = adj[a][i];
            if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs_bmatching(B[b]))) {
                used[a] = true;
                A[a] = b;
                B[b] = a;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int match = 0, flow;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        memset(dist, 0, sizeof(dist));
        memset(used, 0, sizeof(used));
        while (1) {
            bfs_bmatching();
            flow = 0;
            memset(idx, 0, sizeof(idx));
            for (int i = 0; i < MAX; ++i)
                if (!used[i] && dfs_bmatching(i)) flow++;
            if (!flow) break;
            match += flow;
        }
        return match;
    }
}b;
