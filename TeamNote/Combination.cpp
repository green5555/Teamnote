struct Combination {
    ll fact[MAX];
    ll safe_mul(ll a, ll b) { return ((a%MOD) * (b%MOD)) % MOD; }
    void init(int n=MAX) {
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = safe_mul(fact[i-1], i);
    }
    ll fast_pow(ll n, ll e) {
        ll ret = 1;
        while (e > 0) {
            if (e % 2) ret = safe_mul(n, ret);
            e /= 2;
            n = safe_mul(n, n);
        }
        return ret;
    }
    ll comb(ll n, ll k) {
        return safe_mul(
                fact[n],
                fast_pow(safe_mul(fact[n-k], fact[k]), MOD-2)
                );
    }
} CM;

// A^{-1} ≡ A^{M-2} (mod M)
// nCr mod M ≡ (n! mod M) ((n-r)! r!)^{M-2} mod M