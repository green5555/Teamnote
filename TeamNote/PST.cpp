const int MAX;
struct PersistentSegmentTree{
    struct Node{
        int value = 0; //반드시 항등원
        int lidx = -1, ridx = -1;
    };
    vector<int> root;
    vector<Node> seg;

    void init(){
        root.clear(); seg.clear();
        root.emplace_back(0);
        seg.emplace_back(); //root
    }

    int make_tree(int prev, int idx, int value, int nl, int nr) {
        int here = seg.size(); seg.emplace_back();
        if(idx < nl || nr < idx) return prev;
        if (nl == nr) {
            seg[here].value = seg[prev].value + value;
            return here;
        }
        int mid = (nl + nr) / 2;
        if (seg[prev].lidx == -1) {
            seg[prev].lidx = seg.size(); seg.emplace_back();
            seg[prev].ridx = seg.size(); seg.emplace_back();
        }
        seg[here].lidx = make_tree(seg[prev].lidx, idx, value, nl, mid);
        seg[here].ridx = make_tree(seg[prev].ridx, idx, value, mid+1, nr);
        seg[here].value = seg[seg[here].lidx].value + seg[seg[here].ridx].value;
        return here;
    }
    void make_tree(int idx, int value){
        root.emplace_back(make_tree(root.back(), idx, value, 0, MAX-1));
    }

    int query(int idx, int l, int r, int nl, int nr){
        if(idx == -1 || nr < l || r < nl) return 0;
        if(l <= nl && nr <= r) return seg[idx].value;
        int mid = (nl + nr)/2;
        return query(seg[idx].lidx, l, r, nl, mid) + query(seg[idx].ridx, l, r, mid+1, nr);
    }
    int query(int root_idx, int l, int r){
        return query(root[root_idx], l, r, 0, MAX-1);
    }
};
