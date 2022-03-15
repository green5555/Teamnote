const int MAX; //MAX = n의 최대값
mint inv[MAX+1], fac[MAX+1], facInv[MAX+1];
void combInit(){
    fac[0] = 1;
    for(int i=1; i<=MAX; ++i)
        fac[i] = (fac[i-1]*i);
    inv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        inv[i] = (mod - mod/i) * inv[mod%i];
    facInv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        facInv[i] = (facInv[i-1]*inv[i]);
}
inline mint comb(int n, int r){
	if(r == 0 || n == r) return 1;
	return (((fac[n]*facInv[r]))*facInv[n-r]);
}

// Method1, with ll
const int MAX, mod=1'000'000'007; //MAX = n의 최대값
ll inv[MAX+1], fac[MAX+1], facInv[MAX+1];
void combInit(){
    fac[0] = 1;
    for(int i=1; i<=MAX; ++i)
        fac[i] = (fac[i-1]*i)%mod;
    inv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        inv[i] = (mod - mod/i) * inv[mod%i]%mod;
    facInv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        facInv[i] = (facInv[i-1]*inv[i])%mod;
}
inline ll comb(int n, int r){
	if(r == 0 || n == r) return 1;
	return (((fac[n]*facInv[r])%mod)*facInv[n-r])%mod;
}

// Method 2
const int mod;
ll combmod[2000][2000];
void combInit(){
	for(int i=0; i<mod; ++i){
		combmod[i][0] = 1;
		for(int j=1; j<=i; ++j)
			combmod[i][j] = (combmod[i-1][j-1] + combmod[i-1][j])%mod;
	}
}
ll comb(ll n, ll k){
	ll ret = 1;
	while(n>0 || k>0){
		ret = (ret * combmod[n%mod][k%mod])%mod;
		n /= mod, k /= mod;
	}
	return ret;
}
