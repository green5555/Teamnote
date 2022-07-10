// O(n^3) or O(m*n^2)
// mat[1][1] ~ mat[n][m]
// matched[i] : matched column of row i
ll mat[501][501];
ll hungarian(int n, int m, vector<int> &ret) {
    const ll INF = 1e18;
    vector<ll> u(n + 1), v(m + 1), p(m + 1), way(m + 1), minv(m + 1);
    vector<int> used(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        fill(minv.begin(), minv.end(), INF);
        fill(used.begin(), used.end(), false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1;
            ll delta = INF;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    ll cur = mat[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    ret.clear(); ret.resize(n+1);
    for (int j = 1; j <= m; ++j) ret[p[j]] = j;

    return -v[0]; //cost
}