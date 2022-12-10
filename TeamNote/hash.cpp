const int MAX = 200;
struct Hashing {
    const ll base;
    vector<mint> ppow;
    constexpr Hashing(int base = 257): base(base) {
        ppow.resize(MAX); ppow[0] = 1;
        for (int i=1; i<MAX; ++i) ppow[i] = ppow[i-1] * base;
    }
    void hash(vector<mint> &h, const string &s) {
        h.clear(); h.resize(s.size() + 1);
        for (int i = 0; i < s.size(); ++i)
            h[i + 1] = (h[i] + (s[i] + 1) * ppow[i]);
    }
    inline mint get(const vector<mint> &h, int l, int len) {
        return (h[l + len] - h[l])* ppow[MAX-1-l];
    }
};



// without mint

const int MAX = 200;
template<ll m = 1000000009, ll b = 257> struct Hashing {
    vector<ll> ppow;
    Hashing() {
        ppow.resize(MAX); ppow[0] = 1;
        for (int i=1; i<MAX; ++i) ppow[i] = (ppow[i-1] * b) % m;
    }
    void hash(vector<ll> &h, string &s) {
        h.clear(); h.resize(s.size() + 1);
        for (int i = 0; i < s.size(); ++i)
            h[i + 1] = (h[i] + (s[i] + 1) * ppow[i]) % m;
    }
    inline ll get(vector<ll> &h, int l, int len) {
        return (h[l + len] - h[l] + m) % m * ppow[MAX-1-l] % m;
    }
};