const int MAX;
struct lazySeg{
	ll seg[MAX*4], lazy[MAX*4];
	void update_lazy(int no, int nl, int nr){
		if(lazy[no] != 0){
			seg[no] += (nr - nl +1)*lazy[no];
			if(nl != nr){
				lazy[no*2] += lazy[no];
				lazy[no*2+1] += lazy[no];
			}
			lazy[no] = 0;
		}
	}
	ll update(int l, int r, ll v, int no, int nl, int nr){
		update_lazy(no, nl, nr);
		if(r<nl || nr<l) return seg[no];
		if(l <= nl && nr <= r){
            lazy[no] = v;
            update_lazy(no, nl, nr);
			return seg[no];
		}
		int mid = (nl+nr)/2;
		return seg[no] = update(l,r,v,no*2,nl,mid) + update(l,r,v,no*2+1,mid+1,nr);
	}
	ll query(int l, int r, int no, int nl, int nr){
		update_lazy(no, nl, nr);
		if(r<nl || nr<l) return 0;
		if(l <= nl && nr <= r) return seg[no];
		int mid = (nl + nr)/2;
		return query(l,r,no*2,nl,mid) + query(l,r,no*2+1,mid+1,nr);
	}
}LS;