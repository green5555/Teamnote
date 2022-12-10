const int MAX;
struct StronglyConnectedComponent {
    int vst[MAX+1], vstn, sccn;
    vector<int> adj[MAX+1];
    stack<int> s;

    int scci[MAX+1]; // i in scc[i]
    vector<vector<int>> scc;

    int DFS(int here) {
        vst[here] = vstn++;
        int ret = vst[here];
        s.push(here);
        for (int &there : adj[here]) {
            if (vst[there] == -1)
                ret = min(ret, DFS(there));
            else if (scci[there] == -1)
                ret = min(ret, vst[there]);
        }
        if (ret == vst[here]) {
            scc.emplace_back(vector<int>());
            auto &V = scc.back();
            while (true) {
                int tmp = s.top();
                s.pop();
                scci[tmp] = sccn;
                V.push_back(tmp);
                if (tmp == here) break;
            }
            ++sccn;
        }
        return ret;
    }

    void make_scc(int V=MAX) {
        scc.clear();
        memset(vst, -1, sizeof(vst));
        memset(scci, -1, sizeof(scci));
        vstn = 0, sccn = 0;
        // TODO : check range
        for (int i = 1; i <= V; ++i)
            if (vst[i] == -1)
                DFS(i);
    }

    vector<vector<int>> make_scc_adj() {
        vector<vector<int>> sadj(scc.size());
        for(int i=0; i<scc.size(); ++i) {
            auto &A = sadj[i];
            for(int x : scc[i])
                for(int y : adj[x])
                    if(scci[x] != scci[y])
                        A.emplace_back(scci[y]);
            sort(all(A));
            A.erase(unique(all(A)), A.end());
        }
        return sadj;
    }
}S;