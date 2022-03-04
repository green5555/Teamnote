const int MAX = 100;
struct BiMatching {
    vector<int> adj[MAX];
    int iter, pa[MAX], pb[MAX], was[MAX];

    bool dfs(int v) {
        was[v] = iter;
        for (int u : adj[v]) {
            if (pb[u] == -1) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        for (int u : adj[v]) {
            if (was[pb[u]] != iter && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
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
            for (int i = 0; i < MAX; i++) {
                if (pa[i] == -1 && dfs(i)) {
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
