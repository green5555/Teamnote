struct StronglyConnectedComponent {
    int discovered[MAX], sccNumber[MAX], cnt1, cnt2;
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
            else if (sccNumber[there] == -1)
                ret = min(ret, discovered[there]);
        }
        if (ret == discovered[here]) {
            scc.emplace_back(vector<int>());
            auto &V = scc.back();
            while (true) {
                int tmp = s.top();
                s.pop();
                sccNumber[tmp] = cnt2;
                V.push_back(tmp);
                if (tmp == here) break;
            }
            ++cnt2;
        }
        return ret;
    }

    void make_SCC(int V) {
        memset(discovered, -1, sizeof(discovered));
        memset(sccNumber, -1, sizeof(sccNumber));
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < V; ++i)
            if (discovered[i] == -1)
                DFS(i);
    }
}S;