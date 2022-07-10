/*
https://rkm0959.tistory.com/186?category=828364
[정의]
- n이 p^2으로 나누어 떨어지면, mo[n] = 0
- n이 k개의 소수로 소인수분해 되면, mo[n] = (-1)^k
  - mo[1] = 1

[성질]
- 서로소인 n, m에 대해서, mo[n*m] = mo[n] * mo[m]
- sum(d : n의 약수){mo[d]} 는 (n == 1) 과 동치이다.
- f(n) = sum(d : n의 약수){g(d)} 면,
  g(n) = sum(d : n의 약수){mo[n/d] * f(d)}. (mobius inversion)
*/

const int m = 1e6+10;
bool sieve[m+1];
int mo[m+1];

void init_mobius() {
	sieve[1] = 1;
	fill(mo, mo+m+1, 1);
	for(int p=2; p<=m; ++p) {
		if(sieve[p]) continue; 
		mo[p] = -1;
		for(int x=p+p; x<=m; x+=p) {
			sieve[x] = 1;
			mo[x] *= -1;
			if((x/p)%p == 0) mo[x] = 0;
		}
	}
}