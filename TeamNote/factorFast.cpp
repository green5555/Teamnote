ll pollard_rho(ll n) {
	mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution <ll> dis(1, n - 1);
	ll x = dis(gen);
	ll y = x;
	ll c = dis(gen);
	ll g = 1;
	while (g == 1) {
		x = (large_mod_mul(x, x, n) + c) % n;
		y = (large_mod_mul(y, y, n) + c) % n;
		y = (large_mod_mul(y, y, n) + c) % n;
		g = gcd(abs(x - y), n);
	}
	return g;
}
// integer factorization O(n^0.25 * logn)
void factorize(ll n, vector<ll>& fl) {
	if (n == 1) {
		return;
	}
	if (n % 2 == 0) {
		fl.push_back(2);
		factorize(n / 2, fl);
	}
	else if (isPrime(n)) {
		fl.push_back(n);
	}
	else {
		ll f = pollard_rho(n);
		factorize(f, fl);
		factorize(n / f, fl);
	}
}
