ll seg[MAX*4];
ll query(int l, int r, int no, int nl, int nr){
    if(r < nl || nr < l) return 0;
    if(l <= nl && nr <=r) return seg[no];
    int mid = (nl + nr)/2;
    return query(l, r, no*2, nl, mid) + query(l, r, no*2+1, mid+1, nr);
}
ll update(int i, ll v, int no, int nl, int nr){
    if(i<nl || nr<i) return seg[no];
    if(nl == i && nr == i) return seg[no] = v; // += v;
    int mid = (nl + nr)/2;
    return seg[no] = update(i,v,no*2,nl,mid) + update(i,v,no*2+1,mid+1,nr);
}