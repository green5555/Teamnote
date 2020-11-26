const int mod = 1000000007;
struct mi{
int v;
mi() { v = 0; }
mi(const ll& x) {
	v = (-mod <= x && x < mod) ? x : x % mod;
	if (v < 0) v += mod;
}
friend ostream& operator<<(ostream& os, const mi& a) { return os << a.v; }
friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
mi operator-() const { return mi(-v); }
mi& operator+=(const mi& m) { if((v+=m.v)>=mod) v-=mod; return *this; }
mi& operator-=(const mi& m) { if((v -= m.v) < 0) v += mod; return *this; }
mi& operator*=(const mi& m) { v = (ll)v*m.v%mod; return *this; }
friend mi ipow(mi a, ll p) {
	mi ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a; return ans;}
friend mi inv(const mi& a) { assert(a.v); return ipow(a, mod - 2); }
mi& operator/=(const mi& m) { return (*this) *= inv(m); }
friend mi operator+(mi a, const mi& b) { return a += b; }
friend mi operator-(mi a, const mi& b) { return a -= b; }
friend mi operator*(mi a, const mi& b) { return a *= b; }
friend mi operator/(mi a, const mi& b) { return a /= b; }
operator int64_t() const {return v; }
};