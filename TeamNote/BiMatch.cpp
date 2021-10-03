const int MAXA, MAXB;
int A[MAXA], B[MAXB];
bool visit[MAXA];
vector<int> adj[MAXA];
bool DFS(int here){
    if(visit[here]) return false;
    visit[here] = true;
    for(int &there : adj[here])
        if(B[there] == -1 || DFS(B[there])){
            // 매칭이 되어있지 않은 정점을 만나거나 이미 매칭된 정점이 다른 정점과 매칭이 가능할 때
            A[here] = there, B[there] = here;
            return true;
        }
    return false;
}
int bimatch(int cap = 1, int n = MAXA-1) { // 1-index
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < cap; ++j) { // src당 몇 번 매칭?
            memset(visit, 0, sizeof(visit));
            ret += DFS(i);
        }
    }
    return ret;
}