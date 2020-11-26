bool vst[MAX]; //i를 센트로이드로 문제를 푼 적이 있는가?
vector<int> adj[MAX]; int sz[MAX];
int get_size(int u, int p) {
    sz[u] = 1;
    for (auto &v : adj[u]) {
        if (v == p || vst[v]) continue;
        sz[u] += get_size(v, u);
    } return sz[u];
}
int get_cen(int u, int p, int cap) { //크기가 cap인 서브트리의 cen
    for (auto &v : adj[u]) {
        if (v == p || vst[v] || sz[v] <= cap / 2) continue;
        return get_cen(v, u, cap);
    } return u;
}
int solve(int u){
    int cen = get_cen(u, u, get_size(u, u)), ans = INF;
    for(auto &v : adj[cen]){/*TODO*/} //cen을 지나는 경로들을 처리
    for(auto &v : adj[cen]){ //분할&정복 : 자식들을 호출
        if(vst[v]) continue; ans = min(ans, solve(v));
    } return ans;
}
