const ll LINF = -(ll(1e9)+10), RINF = ll(1e9)+10;
struct dynamiclazyseg{
	struct node{
		int lc, rc; //자식의 인덱스
		ll x; //값
	};
	vector<node> seg;
	vector<ll> lazy;

	//TODO
	const ll ID = 0, LID = 0;
	ll merge(ll x, ll y, ll xl, ll xr){
		return x+y;
	}
	//lazy[no]에 v를 추가로 태깅한다.
	void tagging(int no, ll v, ll xl, ll xr){ 
		lazy[no] += v;
	}
	//seg[no].x에 lazy[no]를 업데이트 한다.
	void update_node(int no, ll xl, ll xr){
		seg[no].x += lazy[no] * (xr - xl + 1);
	}

	int make_node(ll xl, ll xr){
		seg.push_back({-1, -1, ID});
		lazy.push_back(LID);
		return seg.size()-1;
	}


	void init(){
		seg.clear();
		lazy.clear();
		make_node(LINF, RINF);
	}
	dynamiclazyseg(){init();}

	void prop(int no, ll xl, ll xr){
		if(lazy[no] == LID) return;
		update_node(no, xl, xr);
		if(xl != xr){
			int m = (xl+xr)/2;
			if(seg[no].lc == -1) {int t = make_node(xl, m);   seg[no].lc = t;}
			if(seg[no].rc == -1) {int t = make_node(m+1, xr); seg[no].rc = t;}
			tagging(seg[no].lc, lazy[no], xl, m);
			tagging(seg[no].rc, lazy[no], m+1, xr);
		}
		lazy[no] = LID;
	}

	ll update(ll l, ll r, ll x, int no, ll xl, ll xr){
		prop(no, xl, xr);
		if(r < xl || xr < l) return seg[no].x;
		if(l <= xl && xr <= r) {
			tagging(no, x, xl, xr);
			prop(no, xl, xr);
			return seg[no].x;
		}
		ll m = (xl+xr)/2;
		if(seg[no].lc == -1) {int t = make_node(xl, m);   seg[no].lc = t;}
		if(seg[no].rc == -1) {int t = make_node(m+1, xr); seg[no].rc = t;}
		return seg[no].x = merge(update(l, r, x, seg[no].lc, xl, m), update(l, r, x, seg[no].rc, m+1, xr), xl, xr);
	}
	void update(ll l, ll r, ll x){
		update(l,r,x,0,LINF,RINF);
	}

	ll query(ll l, ll r, int no, ll xl, ll xr){
		if(no == -1 || xr < l || r < xl) return ID;
		prop(no, xl, xr);
		if(l <= xl && xr <= r) return seg[no].x;
		ll m = (xl+xr)/2;
		return merge(query(l, r, seg[no].lc, xl, m), query(l, r, seg[no].rc, m+1, xr), xl, xr);
	}
	ll query(ll l, ll r){
		return query(l,r,0,LINF,RINF);
	}
}s;