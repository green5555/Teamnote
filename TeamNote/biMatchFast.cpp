const int MAX = 100;
struct BiMatching {
    vector<int> adj[MAX];
    int iter, A[MAX], B[MAX], was[MAX];

    bool dfs(int u) {
        was[u] = iter;
        for (int v : adj[u]) {
            if (B[v] == -1) {
                A[u] = v;
                B[v] = u;
                return true;
            }
        }
        for (int v : adj[u]) {
            if (was[B[v]] != iter && dfs(B[v])) {
                A[u] = v;
                B[v] = u;
                return true;
            }
        }
        return false;
    }

    int biMatch() {
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        memset(was, 0, sizeof(was));
        iter = 0;
        int res = 0;
        while (true) {
            iter++;
            int add = 0;
            for (int i = 0; i < MAX; i++) {
                if (A[i] == -1 && dfs(i)) {
                    add++;
                }
            }
            if (add == 0) {
                break;
            }
            res += add;
        }
        return res;
    }
}
