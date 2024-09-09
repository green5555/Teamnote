typedef unsigned long long ull;
ll large_mod_mul(ll a, ll b, ll m) {
	return ll((__int128)a*(__int128)b%m);
}
// calculate n^k % m
ll modpow(ll n, ll k, ll m) {
	ll ret = 1;
	n %= m;
	while (k) {
		if (k & 1) ret = large_mod_mul(ret, n, m);
		n = large_mod_mul(n, n, m);
		k /= 2;
	}
	return ret;
}
bool test_witness(ull a, ull n, ull s) {
	if (a >= n) a %= n;
	if (a <= 1) return true;
	ull d = n >> s;
	ull x = modpow(a, d, n);
	if (x == 1 || x == n-1) return true;
	while (s-- > 1) {
		x = large_mod_mul(x, x, n);
		if (x == 1) return false;
		if (x == n-1) return true;
	}
	return false;
}
// test whether n is prime based on miller-rabin test O(logn*logn)
bool isPrime(ull n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;
	ull d = n >> 1, s = 1;
	for(; (d&1) == 0; s++) d >>= 1;
#define T(a) test_witness(a##ull, n, s)
		if (n < 4759123141ull) return T(2) && T(7) && T(61);
	return T(2) && T(325) && T(9375) && T(28178)
	&& T(450775) && T(9780504) && T(1795265022);
#undef T
}
