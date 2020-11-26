const int MAX, MOD; //MAX = n의 최대값
ll inv[MAX+1], fac[MAX+1], facInv[MAX+1];
void combInit(){
    fac[0] = 1;
    for(int i=1; i<=MAX; ++i) fac[i] = (fac[i-1]*i)%MOD;
    inv[1] = 1;
    for(int i=2; i<=MAX; ++i) inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
    facInv[1] = 1;
    for(int i=2; i<=MAX; ++i) facInv[i] = (facInv[i-1]*inv[i])%MOD;
}
inline ll comb(int n, int r){
	if(r == 0 || n == r) return 1;
	return (((fac[n]*facInv[r])%MOD)*facInv[n-r])%MOD;
}
inline ll divmod(ll a, ll b){ // return (a/b)%MOD, MOD = prime
	return (a*fastPow(b, MOD-2))%MOD;
}