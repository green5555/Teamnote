const int MOD;
ll fastPow(ll a, ll b){
	if(b==0) return 1;
	if(b&1) return (a * fastPow(a, b-1))%MOD;
	auto tmp = fastPow(a, b/2);
	return (tmp * tmp)%MOD;
}
// return (a/b)%MOD, MOD = prime
inline ll divmod(ll a, ll b){
	return (a*fastPow(b, MOD-2))%MOD;
}