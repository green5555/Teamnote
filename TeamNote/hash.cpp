ll fastPow(ll a, ll b, ll mod){
    if(b==0) return 1;
    if(b&1) return (a * fastPow(a, b-1, mod))%mod;
    auto tmp = fastPow(a, b/2, mod); return (tmp * tmp)%mod;
}
struct Hashing{
    const ll base=31, m=1e9+9;
    int sz;
    vector<ll> ppow, h;
    Hashing(const string &s){
        sz = s.size();
        ppow.resize(sz);
        ppow[0] = 1;
        for(int i=1; i<sz; ++i) {
            ppow[i] = (ppow[i - 1] * base) % m;
        }
        h.resize(sz+1);
        for(int i=0; i<sz; ++i)
            h[i+1] = (h[i] + (s[i]+1) * ppow[i]) % m;
    }
    ll get(int l, int r){
        return (h[r+1] - h[l] + m) % m * fastPow(ppow[l], m-2, m) % m;
    }
    ll compare(int l1, int len, Hashing &s2, int l2){
        ll v1 = (h[l1+len] - h[l1] + m) % m;
        ll v2 = (s2.h[l2+len] - s2.h[l2] + m) % m;
        if(l1 < l2) v1 = (v1 * ppow[l2 - l1]) % m;
        if(l1 > l2) v2 = (v2 * ppow[l1 - l2]) % m;
        return v1 == v2;
    }
};
