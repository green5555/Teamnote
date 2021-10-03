struct SegTree {
    ll seg[MAX*4];
    ll (*func)(ll a, ll b), fail;
    ll init(vector<ll> &a, int no, int nl, int nr) {
        if(nl == nr) return seg[no] = a[nl];
        int mid = (nl + nr)/2;
        return seg[no] = func(init(a,no*2,nl,mid), init(a,no*2+1,mid+1,nr));
    }
    ll query(int l, int r, int no, int nl, int nr){
        if(r < nl || nr < l) return fail;
        if(l <= nl && nr <=r) return seg[no];
        int mid = (nl + nr)/2;
        return func(query(l, r, no*2, nl, mid), query(l, r, no*2+1, mid+1, nr));
    }
    ll update(int i, ll v, int no, int nl, int nr) {
        if(i<nl || nr<i) return seg[no];
        if(nl == nr) return seg[no] = v; // += v;
        int mid = (nl + nr)/2;
        return seg[no] = func(update(i,v,no*2,nl,mid), update(i,v,no*2+1,mid+1,nr));
    }
} SEG;


// = main ========================

	SEG.func = [](ll a, ll b) {
		return (ll)(a + b);
	};
    SEG.fail = 0;