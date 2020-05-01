const int MAX;
struct HeavyLightDecomposition{
    struct SegmentTree{
        int seg[MAX*4] = {};
        int query(int l, int r, int node, int nl, int nr){
            if(r < nl || nr < l) return 0;
            if(l <= nl && nr <=r) return seg[node];
            int mid = (nl + nr)/2;
            return max(query(l, r, node*2, nl, mid), query(l, r, node*2+1, mid+1, nr));
        }
        int query(int l, int r){
            if(l > r) return 0;
            return query(l, r, 1, 0, MAX-1);
        }
        int update(int index, int value, int node, int nl, int nr){
            if(index<nl || nr<index) return seg[node];
            if(nl == nr) return seg[node] = value;
            int mid = (nl + nr)/2;
            return seg[node] = max(update(index,value,node*2,nl,mid), update(index,value,node*2+1,mid+1,nr));
        }
        void update(int index, int value){
            update(index, value, 1, 0, MAX-1);
        }
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
        if(chain[DFS_cnt[x]] == chain[DFS_cnt[y]]){ //같은 체인에 속하는 경우
            if(level[x] > level[y]) swap(x,y);
            //노드에 가중치가 달린 경우 DFS_cnt[x]+1
            return S.query(DFS_cnt[x] + 1, DFS_cnt[y]);
        }
        int x_head = chain[DFS_cnt[x]], y_head = chain[DFS_cnt[y]];
        if(level[x_head] > level[y_head])
            return max(S.query(DFS_cnt[x_head], DFS_cnt[x]) , query(parent[x_head], y));
        else
            return max(S.query(DFS_cnt[y_head], DFS_cnt[y]) , query(x, parent[y_head]));
    }

    int LCA(int x, int y){ //같은 체인에 속하는 경우 루트에 가까운 정점이 LCA
        if(chain[DFS_cnt[x]] == chain[DFS_cnt[y]])
            return level[x] < level[y] ? x : y;
        int x_head = chain[DFS_cnt[x]], y_head = chain[DFS_cnt[y]];
        if(level[x_head] > level[y_head])
            return LCA(parent[x_head], y);
        else return LCA(x, parent[y_head]);
    }
}H;