inline ll safe_add (const ll& a, const ll& b) {
    if (a > -LINF && b > -LINF) return a+b;
    if (a > -LINF) return a;
    if (b > -LINF) return b;
    return -LINF;
}
struct GoldSeg {
    struct Node {
        ll lval = -LINF, rval = -LINF, val = -LINF, all = 0;
        Node operator+ (const Node& n) const { return {safe_add(lval,n.lval), safe_add(rval,n.rval), safe_add(val,n.val), safe_add(all,n.all)}; }
    } seg[MAX*4];
    Node func(Node a, Node b) {
        return {
                max({a.lval, safe_add(a.all,b.lval)}),
                max({safe_add(a.rval,b.all), b.rval}),
                max({a.val, b.val, safe_add(a.rval,b.lval)}),
                max({safe_add(a.all,b.all)})
        };
    }
    Node init(vector<Node> &a, int no, int nl, int nr) {
        if(nl == nr) return seg[no] = a[nl];
        int mid = (nl + nr)/2;
        return seg[no] = func(init(a,no*2,nl,mid), init(a,no*2+1,mid+1,nr));
    }
    Node query(int l, int r, int no, int nl, int nr){
        if(r < nl || nr < l) return Node();
        if(l <= nl && nr <= r) return seg[no];
        int mid = (nl + nr)/2;
        return func(query(l, r, no*2, nl, mid), query(l, r, no*2+1, mid+1, nr));
    }
    Node update(int i, Node v, int no, int nl, int nr) {
        if (i < nl || nr < i) return seg[no];
        if (nl == nr) return seg[no] = seg[no]+v; // = v
        int mid = (nl + nr) / 2;
        return seg[no] = func(update(i, v, no * 2, nl, mid), update(i, v, no * 2 + 1, mid + 1, nr));
    }
} GSEG;

vector<GoldSeg::Node> nodes;