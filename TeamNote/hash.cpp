struct Hashing{
    const ll base=31, m=1e9+9; //random base : 0.3m ~ 0.7m?
    int sz;
    vector<ll> ppow, h;
    Hashing(const string &s){
        sz = s.size();
        ppow.resize(sz);
        ppow[0] = 1;
        for(int i=1; i<sz; ++i)
            ppow[i] = (ppow[i - 1] * base) % m;
        h.resize(sz+1);
        for(int i=0; i<sz; ++i)
            h[i+1] = (h[i] + (s[i]+1) * ppow[i]) % m;
    }
    inline ll get(int l, int len){
        return (h[l+len] - h[l] + m) % m;
    }
    bool compare(int l1, int len, Hashing &h2, int l2){
        ll v1 = get(l1, len), v2 = h2.get(l2, len);
        if(l1 < l2) v1 = (v1 * ppow[l2 - l1]) % m;
        if(l1 > l2) v2 = (v2 * ppow[l1 - l2]) % m;
        return v1 == v2;
    }
};
