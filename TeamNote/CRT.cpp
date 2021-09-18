//ac + bd = gcd(a,b)가 되는 (c,d)를 찾는다
pll extended_gcd(ll a, ll b) {
	if(b == 0) return make_pair(1, 0);
	pll t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

//ax = gcd(a,m)%m 이 되는 x를 찾는다
ll modinverse(ll a, ll m) {
	return (extended_gcd(a, m).first % m + m) % m;
}

// x % M[i] = A[i]인 x의 최소값은?
ll CRT_nocoprime(vector<ll> &M, vector<ll> &A) {
	ll retA=A[0], retM=M[0];
	for(int i=1; i<M.size(); ++i){
		ll m2=retM, a2=retA, g=gcd(M[i], retM);
		if((A[i]-a2)%g) return -1;
		retM=M[i]*m2/g;
		ll m=M[i]/g; ll v=((A[i]-a2)/g%m+m)%m;
		ll w=(extended_gcd(m2/g%m, M[i]/g).first%m+m)%m;
		retA=a2+v*w%m*m2;
	}
	return retA;
}
