const int MAX = 100;
vector<pii> graph[MAX]; // { next vertex id, edge id }
int up[MAX], vst[MAX], vtime;
vector<int> stk;
int is_cut[MAX]; // v is cut vertex if is_cut[v] > 0
vector<int> bridge; // list of edge ids
vector<int> bcc_edges[MAX]; // list of edge ids in a bcc
int bcc_cnt;
void dfs(int no, int pe) { // node, parent edge
    up[no] = vst[no] = ++vtime;
    int child = 0;
    for (const auto& e : graph[no]) {
        int next = e.xx, eid = e.yy;
        if (eid == pe) continue;
        if (vst[next] == 0) {
            stk.push_back(eid);
            ++child;
            dfs(next, eid);
            if (up[next] == vst[next]) bridge.push_back(eid);
            if (up[next] >= vst[no]) {
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
        else if (vst[next] < vst[no]) {
            stk.push_back(eid);
            up[no] = min(up[no], vst[next]);
        }
    }
    if (pe == -1 && is_cut[no] == 1)
        is_cut[no] = 0;
}
void get_bcc() {
    vtime = 0;
    memset(vst, 0, sizeof(vst));
    memset(is_cut, 0, sizeof(is_cut));
    bridge.clear();
    for (int i = 0; i < MAX; ++i) bcc_edges[i].clear();
    bcc_cnt = 0;
    for (int i = 0; i < MAX; ++i) {
        if (vst[i] == 0)
            dfs(i, -1);
    }
}