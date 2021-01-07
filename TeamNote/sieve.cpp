//소수 판별
const int MAX = 1000000;
bool sieve[MAX+1];
void find_prime(){
	sieve[0] = sieve[1] = 1;
	for(ll i=2; i*i<=MAX; ++i){ // i<=MAX if want prime vector
		if(sieve[i] == 0)
			for(ll j=i*i; j<=MAX; j+=i)
				sieve[j] = 1;
	}
}

//소인수분해
const int MAX = 1000000;
int sieve[MAX+1];
void find_prime(){
	memset(sieve, -1, sizeof(sieve));
	for(ll i=2; i*i<=MAX; ++i)
		if(sieve[i] == -1)
			for(ll j=i*i; j<=MAX; j+=i)
				if(sieve[j] == -1)
					sieve[j] = i;
}
void print_factor(int n){
	while(sieve[n] != -1){
		cout << sieve[n] << '\n';
		n /= sieve[n];
	}
    cout << n << '\n';
}


//1~N의 약수의 개수 구하기 O(NlogN)
const int MAX = 1000000;
int sieve[MAX+1];
void num_of_divisors() {
	for (int i = 1; i <= MAX; ++i)
		for (int j = i; j <= MAX; j += i)
			sieve[j] += 1;
}


// 오일러 피 함수 O(NloglogN) : 0 < x < n && gcd(n, x) = 1 인 x의 개수
const int MAX = 1000000;
int sieve[MAX+1];
void euler_phi() {
	for (int i = 1; i <= MAX; ++i) sieve[i] = i;
	for (int i = 2; i <= MAX; ++i)
		if (sieve[i] == i)
			for (int j = i; j <= MAX; j += i)
				sieve[j] -= sieve[j] / i;
}
