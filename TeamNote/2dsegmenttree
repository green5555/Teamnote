const int MAX=0;
struct SegmentTree2d{
    SegmentTree seg[MAX*4];
    ll query(int l, int r, int yl, int yr, int no=1, int nl=0, int nr=MAX-1){
        if(r < nl || nr < l) return 0;
        if(l <= nl && nr <=r) return seg[no].query(yl, yr);
        int m = (nl + nr)/2;
        return query(l, r, yl, yr, no*2, nl, m) + query(l, r, yl, yr, no*2+1, m+1, nr);
    }
    void update(int i, int yi, ll v, int no=1, int nl=0, int nr=MAX-1){
        if(i<nl || nr<i) return;
        seg[no].update(yi, v);
        if(nl == nr) return;
        int m = (nl + nr)/2;
        update(i,yi,v,no*2,nl,m), update(i,yi,v,no*2+1,m+1,nr);
    }
}s;
