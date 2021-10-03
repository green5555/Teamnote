struct SparseTable {
    ll arr[MAX][30], lg2[MAX];  // 30=lg2(1e9), 20=lg2(1e6)
    ll (*func)(ll a, ll b);     // f(a,b,c) == f(f(a,b), f(b,c))

    void init(int n) {
        for (int j = 1; (1ull << j) < n; ++j) {
            lg2[(1ull << j)] = j;
            for (int i = 0; i + (1ull << (j-1)) < n; ++i) {
                arr[i][j] = func(arr[i][j-1], arr[i + (1ull << (j-1))][j-1]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (!lg2[i]) lg2[i] = lg2[i-1];
        }
    }
    ll query(int l, int r) {
        ll lefts = r - (1ull << lg2[r - l + 1]) + 1;
        return func(arr[l][lg2[r - l + 1]], arr[lefts][lg2[r - l + 1]]);
    }
};