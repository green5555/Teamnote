int vst[MAX], sccn[MAX], cnt1, cnt2;
vector<int> adj[MAX]; vector<vector<int>> scc;
stack<int> s;
int DFS(int here) {
    vst[here] = cnt1++;
    int ret = vst[here];
    s.push(here);
    for (int &there : adj[here]) {
        if (vst[there] == -1) ret = min(ret, DFS(there));
        else if (sccn[there] == -1) ret = min(ret, vst[there]);
    }
    if (ret == vst[here]) {
        scc.emplace_back(vector<int>());
        auto &V = scc.back();
        while (true) {
            int tmp = s.top(); s.pop();
            sccn[tmp] = cnt2; V.push_back(tmp);
            if (tmp == here) break;
        }
        ++cnt2;
    }
    return ret;
}
void make_SCC(int V) {
    memset(vst, -1, sizeof(vst));
    memset(sccn, -1, sizeof(sccn));
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < V; ++i) if (vst[i] == -1) DFS(i);
}