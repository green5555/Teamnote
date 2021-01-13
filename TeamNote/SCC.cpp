const int MAX;
struct StronglyConnectedComponent {
    int discovered[MAX], sccn[MAX], cnt1, cnt2;
    vector<int> adj[MAX];
    stack<int> s;
    vector<vector<int>> scc;

    int DFS(int here) {
        discovered[here] = cnt1++;
        int ret = discovered[here];
        s.push(here);
        for (int &there : adj[here]) {
            if (discovered[there] == -1)
                ret = min(ret, DFS(there));
            else if (sccn[there] == -1)
                ret = min(ret, discovered[there]);
        }
        if (ret == discovered[here]) {
            scc.emplace_back(vector<int>());
            auto &V = scc.back();
            while (true) {
                int tmp = s.top();
                s.pop();
                sccn[tmp] = cnt2;
                V.push_back(tmp);
                if (tmp == here) break;
            }
            ++cnt2;
        }
        return ret;
    }

    void make_SCC(int V=MAX) {
        scc.clear();
        memset(discovered, -1, sizeof(discovered));
        memset(sccn, -1, sizeof(sccn));
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < V; ++i)
            if (discovered[i] == -1)
                DFS(i);
    }
}S;
