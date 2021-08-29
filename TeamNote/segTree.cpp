const int MAX=0;
struct SegmentTree{
    ll seg[MAX*4];
    ll query(int l, int r, int no=1, int nl=0, int nr=MAX-1){
        if(r < nl || nr < l) return 0;
        if(l <= nl && nr <=r) return seg[no];
        int m = (nl + nr)/2;
        return (query(l, r, no*2, nl, m) + query(l, r, no*2+1, m+1, nr));
    }
    ll update(int i, ll v, int no=1, int nl=0, int nr=MAX-1){
        if(i<nl || nr<i) return seg[no];
        if(nl == nr) return seg[no] = v; // += v;
        int m = (nl + nr)/2;
        return seg[no] = (update(i,v,no*2,nl,m) + update(i,v,no*2+1,m+1,nr));
    }
}s;
