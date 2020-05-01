const int MAX; //정점의 최대 개수
struct twoSAT {
    int discovered[MAX * 2], sccNumber[MAX * 2], cnt1, cnt2;
    vector<int> adj[MAX * 2];
    stack<int> S;
    int scc(int here) {
        discovered[here] = cnt1++;
        int ret = discovered[here];
        S.push(here);
        for (int &there : adj[here]) {
            if (discovered[there] == -1)
                ret = min(ret, scc(there));
            else if (sccNumber[there] == -1)
                ret = min(ret, discovered[there]);
        }
        if (ret == discovered[here]) {
            while (true) {
                int tmp = S.top();
                S.pop();
                sccNumber[tmp] = cnt2;
                if (tmp == here) break;
            }
            ++cnt2;
        }
        return ret;
    }
    bool solve(int V=MAX) {
        V *= 2;
        memset(discovered, -1, sizeof(discovered));
        memset(sccNumber, -1, sizeof(sccNumber));
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < V; ++i)
            if (discovered[i] == -1)
                scc(i);
        for (int i = 0; i < V; i += 2)
            if (sccNumber[i] == sccNumber[i + 1])
                return vector<int>();
        vector<int> ans(V / 2, -1);
        int arr[MAX * 2];
        for (int i = 0; i < V; ++i)
            arr[i] = i;
        sort(arr, arr + V, [&](int &a, int &b) {
            if (sccNumber[a] != sccNumber[b])
                return sccNumber[a] > sccNumber[b];
            return a < b;
        });
        for (int i = 0; i < V; ++i)
            if (ans[arr[i] / 2] == -1)
                ans[arr[i] / 2] = !(arr[i] & 1);
        return ans;
    }
    void makeEdge(int X, bool XisTrue, int Y, bool YisTrue) {
        adj[2 * X + !XisTrue].push_back(2 * Y + YisTrue);
        adj[2 * Y + !YisTrue].push_back(2 * X + XisTrue);
    }
}T;