const int MAX;
struct SegmentTree{
    //query, update시 l > r이 들어올 수 있음.
}S;
vector<int> adj[MAX]; //입력 필요
int level[MAX]={}, sub_size[MAX]={}, parent[MAX]={};
int DFS_cnt[MAX]={}, dn=0, chain[MAX]={}, tail[MAX]={};
void make_tree(int here, int p){
    parent[here] = p;
    sub_size[here] = 1;
    for(int &i : adj[here]){
        if(i == parent[here]) continue;
        level[i] = level[here]+1;
        make_tree(i, here);
        sub_size[here] += sub_size[i];
    }
}
// DFS_cnt[i] = i번 정점의 DFS 넘버
// chain[i] = DFS 넘버가 i인 정점이 속하는 체인 넘버
// 체인의 머리의 노드 넘버는, 체인 넘버와 동일하다
// tail[i] = 체인 넘버가 i인 체인의 꼬리의 DFS 넘버
void HLD(int here, int p, int chain_cnt){
    DFS_cnt[here] = ++dn;
    chain[dn] = chain_cnt;
    tail[chain_cnt] = dn;
    int heavy_idx = -1;
    for(int &i : adj[here])
        if(i != p && (heavy_idx == -1 || sub_size[i] > sub_size[heavy_idx]))
            heavy_idx = i;
    if(heavy_idx != -1) HLD(heavy_idx, here, chain_cnt);
    for(int &i : adj[here])
        if(i != p && i != heavy_idx)
            HLD(i, here, i);
}
void update(int node, int value){
    S.update(DFS_cnt[node], value);
}
int query(int x, int y){
    if(chain[DFS_cnt[x]] == chain[DFS_cnt[y]]){ //같은 체인
        if(level[x] > level[y]) swap(x,y);
        //노드에 가중치가 달린 경우 DFS_cnt[x]+1 -> DFS_cnt[x]
        return S.query(DFS_cnt[x] + 1, DFS_cnt[y]);
    }
    int x_head = chain[DFS_cnt[x]], y_head = chain[DFS_cnt[y]];
    if(level[x_head] > level[y_head])
        return max(S.query(DFS_cnt[x_head], DFS_cnt[x]) , query(parent[x_head], y));
    else
        return max(S.query(DFS_cnt[y_head], DFS_cnt[y]) , query(x, parent[y_head]));
}