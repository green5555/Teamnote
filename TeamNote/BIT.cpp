const int MAX;
struct BIT{
    ll seg[MAX+1] = {};
    void clear(){memset(seg, 0, sizeof(seg));}
    ll psum(int idx){
        ll ret = 0;
        while(idx > 0){ ret += seg[idx], idx -= idx & -idx; }
        return ret;
    }
    ll query(int l, int r){
        ll ret = psum(r); if(l>0) ret -= psum(l-1);
        return ret;
    }
    void update(int idx, ll a=1) {
        while (idx <= MAX){ seg[idx] += a; idx += idx & -idx; }
    }
}


int kth(int k){
    int ret = 0;
    for(int i=30; i>=0; --i){
        int pivot = ret + (1<<i);
        if(pivot <= MAX && seg[pivot] < k){
            k -= seg[pivot];
            ret = pivot;
        }
    }
    return ret+1;
}
