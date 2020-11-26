//FAST I/O
namespace fio {
	const int BSIZE = 524288; char buffer[BSIZE]; int p = BSIZE;
	inline char readChar() {
		if(p == BSIZE) { fread(buffer, 1, BSIZE, stdin); p = 0; }
		return buffer[p++];
	}
	int readInt() {
		char c = readChar();
		while ((c < '0' || c > '9') && c != '-') c = readChar();
		int ret = 0; bool neg = c == '-';
		if (neg) c = readChar();
		while (c >= '0' && c <= '9') {
			ret = ret * 10 + c - '0'; c = readChar();
		}
		return neg ? -ret : ret;
	}
}
int x = fio::readInt();

//strtok 파싱
string input = "how to,split!string";
char *token = strtok(input, " ,!");
while(token){ cout << token << '\n'; token = strtok(0, " ,!"); }

//신발끈 정리 - 변이 교차하지 않는 다각형의 넓이
for(int i=0; i<n; ++i)
	area += X[i]*Y[(i+1)%len] - X[i]*Y[(i+len-1)%len];;
return abs(area/2);

//비트마스크
__builtin_popcount(bits) // 켜져있는 비트의 개수
__builtin_ctz(bits) //최하위 비트의 인덱스
(bits & -bits) //최하위 비트의 실제 값
for(int i=bits; i; i=(i-1)&bits) //모든 부분집합 순회

bitset<64> B(42); // ...00101010
string S = B.to_string();
bitset<64> B2("101010");
cout << B2.to_ullong(); // 42
//string stream
int num;
stringstream stream; 
string string = "1 2 3 a 4"; 
stream.str(string); 
while( stream >> num )
	cout << num << ' '; //1 2 3

//cout 자리수 설정
cout.precision(X); cout << fixed;

// comparator overload
auto cmp = [](seg a, seg b){return a.func() < b.func(); };
set<seg, decltype(cmp)> s(cmp);
map<seg, int, decltype(cmp)> mp(cmp);
priority_queue<seg, vector<seg>, decltype(cmp)> pq(cmp); // max heap

// hash func overload
struct hasher {
    size_t operator()(const pii &x)const{
        return hash<ll>()(((ll)x.first)^(((ll)x.second)<<32));
    }
    size_t operator()(const state &s) const {
        size_t res = 17;
        res = res * 31 + hash<string>()(s.pro);
        res = res * 31 + hash<int>()(s.x);
        res = res * 31 + hash<int>()(s.y);
        res = res * 31 + hash<char>()(s.prev_p);
        return res;
    }
};
unordered_map<state, int, hasher> dp;

//safe rand
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
cout << uniform_int_distribution<int>(0, 10)(rng); //return 0,...,10

//0.9초동안 돌리는 랜덤
double start_time = clock();
while(1){
	//...
	if((clock() - start_time) / CLOCKS_PER_SEC >= 0.99) break; // 0.99s
}

//gcc 최적화
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")