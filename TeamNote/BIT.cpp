// idx : [0 ~ MAX)

const int MAX = 0;
struct BIT{
    ll seg[MAX+2];
    void clear(){memset(seg, 0, sizeof(seg));}
    ll psum(int idx){ ++idx;
        ll ret = 0;
        while(idx > 0){ ret += seg[idx], idx -= idx & -idx; }
        return ret;
    }
    ll query(int l, int r){
        ll ret = psum(r); if(l>0) ret -= psum(l-1);
        return ret;
    }
    void update(int idx, ll a=1) { ++idx;
        while (idx <= MAX){ seg[idx] += a; idx += idx & -idx; }
    }
}s;

// return : psum(x) = k를 만족하는 x
//          k가 전체 합보다 크면 MAX 리턴.
int kth(ll k){
    int ret = 0;
    for(int i=30; i>=0; --i){
        int pivot = ret + (1<<i);
        if(pivot <= MAX && seg[pivot] < k){
            k -= seg[pivot];
            ret = pivot;
        }
    }
    return ret;
}