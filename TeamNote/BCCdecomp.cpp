const int MAX = 10010;
struct BCC_decomposition {
    //단절점을 기준으로 BCC를 나눈다.
    //TODO : adj 채우기, v = [1~n]
    //belong[i] : i번 정점이 속해있는 BCC 번호
    //bcc[i] : i번 BCC에 속해있는 정점들의 번호
    int piv, cpiv, dfsn[MAX], low[MAX], par[MAX], vst[MAX];
    vector<int> adj[MAX], belong[MAX];

    void dfs(int x, int p) {
        dfsn[x] = low[x] = ++piv;
        par[x] = p;
        for (int &y : adj[x]) {
            if (y == p) continue;
            if (!dfsn[y]) {
                dfs(y, x);
                low[x] = min(low[x], low[y]);
            } else low[x] = min(low[x], dfsn[y]);
        }
    }

    void color(int x, int c) {
        if (c > 0) belong[x].push_back(c);
        vst[x] = 1;
        for (int &y : adj[x]) {
            if (vst[y]) continue;
            if (dfsn[x] <= low[y]) { //단절점
                belong[x].push_back(++cpiv);
                color(y, cpiv);
            } else color(y, c);
        }
    }

    vector<vector<int>> bcc;

    void solve(int n) {
        for(int i=1; i<=n; ++i)
            if(!par[i]) dfs(i, i);
        for(int i=1; i<=n; ++i)
            if(!vst[i]) color(i, 0);
        bcc.resize(cpiv);
        for (int i = 1; i <= n; ++i) {
            for (int &b : belong[i])
                bcc[b - 1].emplace_back(i);
        }
    }
}b;
