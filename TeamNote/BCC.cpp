const int MAX = 100;
struct{
    vector<pii> adj[MAX]; // { next vertex id, edge id }
    int up[MAX], visit[MAX], vtime;
    vector<int> stk;
    int is_cut[MAX]; // v is cut vertex if is_cut[v] > 0
    vector<int> bridge; // list of edge ids
    vector<int> bcc_edges[MAX]; // list of edge ids in a bcc
    int bcc_cnt;
    void dfs(int no, int pe) { // node, parent edge
        up[no] = visit[no] = ++vtime;
        int child = 0;
        for (const auto& e : adj[no]) {
            int next = e.xx, eid = e.yy;
            if (eid == pe) continue;
            if (visit[next] == 0) {
                stk.push_back(eid);
                ++child;
                dfs(next, eid);
                if (up[next] == visit[next]) bridge.push_back(eid);
                if (up[next] >= visit[no]) {
                    ++bcc_cnt;
                    do {
                        auto lasteid = stk.back();
                        stk.pop_back();
                        bcc_edges[bcc_cnt].push_back(lasteid);
                        if (lasteid == eid) break;
                    } while (!stk.empty());
                    is_cut[no]++;
                }
                up[no] = min(up[no], up[next]);
            }
            else if (visit[next] < visit[no]) {
                stk.push_back(eid);
                up[no] = min(up[no], visit[next]);
            }
        }
        if (pe == -1 && is_cut[no] == 1)
            is_cut[no] = 0;
    }
    // find BCCs & cut vertexs & bridges in undirected graph O(V+E)
    void get_bcc() {
        vtime = 0;
        memset(visit, 0, sizeof(visit));
        memset(is_cut, 0, sizeof(is_cut));
        bridge.clear();
        for (int i = 0; i < MAX; ++i) bcc_edges[i].clear();
        bcc_cnt = 0;
        for (int i = 0; i < MAX; ++i) {
            if (visit[i] == 0)
                dfs(i, -1);
        }
    }
}BCC;
