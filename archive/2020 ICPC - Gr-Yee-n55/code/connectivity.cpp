struct UnionFindWithRollback{
    int parent[100100];
    stack<tuple<int,int,int>> S;
    UnionFindWithRollback(){
        memset(parent, -1, sizeof(parent));
    }
    int find(int x){
        if(parent[x]<0) return x; return find(parent[x]);
    }
    bool merge(int x, int y){
        x = find(x), y = find(y); if(x == y) return 0;
        if(parent[x] < parent[y]) swap(x,y);
        S.push({x, y, parent[x]});
        parent[y] += parent[x]; parent[x] = y; return 1;
    }
    void rollback(){
        auto [x,y,sz] = S.top();
        parent[y] -= sz; parent[x] = sz; S.pop();
    }
}UF;
int query[100100][3];
vector<pii> tree[400400];
//라이프타임이 s~e인 간선 u-v를 분할-정복 트리의 노드에 추가.
//조건 : l~r에 살아있는, 즉, s <= l && r <= e
void init(int u, int v, int s, int e, int no, int l, int r){
    if(e < l || r < s) return;
    if(s <= l && r <= e) {
        tree[no].push_back({u, v}); return;
    }
    int mid = (l+r)/2;
    init(u, v, s, e, no*2, l, mid); init(u, v, s, e, no*2+1, mid+1, r);
}
void solve(int no, int l, int r){
    //query[no]를 UF에 추가
    int change = 0;
    for(auto &p : tree[no]) change += UF.merge(p.xx, p.yy);
    //리프에 도달했으면, 현재 구간이 쿼리라면 해결!
    if(l == r && query[l][0] == 3)
        cout << (UF.find(query[l][1]) == UF.find(query[l][2])) << '\n';
    if(l != r){
        int mid = (l+r)/2; solve(no*2, l, mid); solve(no*2+1, mid+1, r);
    }
    //롤백
    while(change--) UF.rollback();
}
void main() {
	//1,2,3 u v : 추가, 제거, 쿼리 (u < v)
    map<pii, int> lifetime_map;
    for(int i=0; i<m; ++i){
        int &u = query[i][1], &v = query[i][2];
        if(query[i][0] == 1){ //간선 추가
            lifetime_map[{u, v}] = i;
        }
        else if(query[i][0] == 2){//간선 삭제
            int s = lifetime_map[{u, v}];
            init(u, v, s, i, 1, 0, m-1);
            lifetime_map.erase({u, v});
        }
    }
    for(auto &p : lifetime_map){
        int u = p.xx.xx, v = p.xx.yy, s = p.yy;
        init(u, v, s, m-1, 1, 0, m-1);
    }
    solve(1, 0, m-1);
}