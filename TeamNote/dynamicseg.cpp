const ll LINF = 0, RINF = ll(1e9)+10;
struct dynamicseg{
    //TODO
    const ll ID = 0;
    ll merge(ll x, ll y){
        return x+y;
    }

    struct node{
        int lc, rc; //자식의 인덱스
        ll x; //값
    };
    vector<node> seg;

    int make_node(ll xl, ll xr){
        seg.push_back({-1, -1, ID});
        return seg.size()-1;
    }

    void init(){
        seg.clear();
        make_node(LINF, RINF);
    }

    ll update(ll i, ll x, int no, ll xl, ll xr){
        if(i < xl || xr < i) return seg[no].x;
        if(xl == xr) {
            //TODO : update seg[no].x <- x
            seg[no].x = x;
            return seg[no].x;
        }
        ll m = (xl+xr)/2;
        if(seg[no].lc == -1) seg[no].lc = make_node(xl, m);
        if(seg[no].rc == -1) seg[no].rc = make_node(m+1, xr);
        return seg[no].x = merge(update(i, x, seg[no].lc, xl, m), update(i, x, seg[no].rc, m+1, xr));
    }
    void update(ll i, ll x){
        update(i,x,0,LINF,RINF);
    }

    ll query(ll l, ll r, int no, ll xl, ll xr){
        if(no == -1 || xr < l || r < xl) return ID;
        if(l <= xl && xr <= r) return seg[no].x;
        ll m = (xl+xr)/2;
        return merge(query(l, r, seg[no].lc, xl, m), query(l, r, seg[no].rc, m+1, xr));
    }
    ll query(ll l, ll r){
        return query(l,r,0,LINF,RINF);
    }
}s;
