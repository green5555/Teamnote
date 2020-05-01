//ac + bd = gcd(a,b)가 되는 (c,d)를 찾는다
pair<long long, long long> extended_gcd(long long a, long long b) {
	if(b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

//ax = gcd(a,m)%m 이 되는 x를 찾는다
long long modinverse(long long a, long long m) {
return (extended_gcd(a, m).first % m + m) % m;
}

//a[i] % n[i] 가 동일한 최소 X를 찾아줌
long long chinese_remainder(long long *a, long long *n, int size) {
	if (size == 1) return *a;
	long long tmp = modinverse(n[0], n[1]);
	long long tmp2 = (tmp * (a[1] - a[0]) % n[1] + n[1]) % n[1];
	long long ora = a[1];
	long long tgcd = gcd(n[0], n[1]);
	a[1] = a[0] + n[0] / tgcd * tmp2;
	n[1] *= n[0] / tgcd;
	long long ret = chinese_remainder(a + 1, n + 1, size - 1);
	n[1] /= n[0] / tgcd;
	a[1] = ora;
	return ret;
}

// mod(π(M))에서 x = B[i] % M[pos+i] 인 x를 구해준다
ll CRT_nocoprime(vector<ll> &B, vector<ll> &M) {
	ll retB=B[0], retM=M[0];
	for(int i=1; i<M.size(); ++i){
		ll m1=M[i], b1=B[i], m2=retM, b2=retB;
		ll g=gcd(m1, m2);
		if((b1-b2)%g) return -1;
		retM=m1*m2/g;
		ll m=m1/g;
		ll v=((b1-b2)/g%m+m)%m;
		ll w=(extended_gcd(m2/g%m, m1/g).first%m+m)%m;
		retB=b2+v*w%m*m2;
	}
	return retB;
}
