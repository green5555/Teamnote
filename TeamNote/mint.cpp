const int mod = 1'000'000'007;
struct mint {
	int val;
	mint() { val = 0; }
	mint(const ll& v) {
		val = (-mod <= v && v < mod) ? v : v % mod;
		if (val < 0) val += mod;
	}

	friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
	friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
	friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

	mint operator-() const { return mint(-val); }
	mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
	mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
	mint& operator*=(const mint& m) { val = (ll)val*m.val%mod; return *this; }
	friend mint ipow(mint a, ll p) {
		mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }

	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
	// operator int64_t() const {return val; }
};
