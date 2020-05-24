// Method 1
const int MAX, MOD; //MAX = n의 최대값
long long inv[MAX+1], fac[MAX+1], facInv[MAX+1];
void combInit(){
    fac[0] = 1;
    for(int i=1; i<=MAX; ++i)
        fac[i] = (fac[i-1]*i) %MOD;
    inv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        inv[i] = (MOD - MOD/i) * inv[MOD%i] %MOD;
    facInv[1] = 1;
    for(int i=2; i<=MAX; ++i)
        facInv[i] = (facInv[i-1]*inv[i]) %MOD;
}
inline long long comb(int n, int r){
	if(r == 0 || n == r) return 1;
	return (((fac[n]*facInv[r])%MOD)*facInv[n-r])%MOD;
}

// Method 2
const int MOD;
long long combMOD[2000][2000];
void combInit(){
	for(int i=0; i<MOD; ++i){
		combMOD[i][0] = 1;
		for(int j=1; j<=i; ++j)
			combMOD[i][j] = (combMOD[i-1][j-1] + combMOD[i-1][j])%MOD;
	}
}
long long comb(long long n, long long k){
	long long ret = 1;
	while(n>0 || k>0){
		ret = (ret * combMOD[n%MOD][k%MOD])%MOD;
		n /= MOD, k /= MOD;
	}
	return ret;
}
