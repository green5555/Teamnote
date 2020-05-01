//소수 판별
const int MAX = 10000000;
bool isPrime[MAX+2];
vector<int> prime;
void find_prime(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqMAX = sqrt(MAX)+1;
	for(long long i=2; i<=sqMAX; ++i)
		if(isPrime[i]){
			prime.push_back(i);
			for(long long j=i*i; j<=MAX; j+=i)
				isPrime[j] = false;
		}
}

//소인수분해
const int MAX = 10000000;
int isPrime[MAX+2];
void find_prime(){
	memset(isPrime, -1, sizeof(isPrime));
	int sqMAX = sqrt(MAX)+1;
	for(long long i=2; i<=sqMAX; ++i)
		if(isPrime[i] == -1)
			for(long long j=i*i; j<=MAX; j+=i)
				if(isPrime[j] == -1)
					isPrime[j] = i;
}
void print_factor(int n){
	while(isPrime[n] != -1){
		cout << isPrime[n] << ' ';
		n /= isPrime[n];
	}
    cout << n;
}

//1~N의 약수의 개수 구하기 O(NlogN)
void num_of_divisors(int n, int ret[]) {
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			ret[j] += 1;
}
//오일러 피 함수 O(n*loglogn)
// 0 < x < n && gcd(n, x) = 1 인 x의 개수
void euler_phi(int n, int ret[]) {
	for (int i = 1; i <= n; ++i) ret[i] = i;
	for (int i = 2; i <= n; ++i)
		if (ret[i] == i)
			for (int j = i; j <= n; j += i)
				ret[j] -= ret[j] / i;
}