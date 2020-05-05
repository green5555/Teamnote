512MB = int * 17,179,869,184

//strtok 파싱
string input = "how to,split!string";
char *token = strtok(input, " ,!");
while(token){
	cout << token << '\n';
	token = strtok(0, " ,!");
}

//cout 자리수 설정
cout.precision(X);
cout << fixed;

//비트마스크
__builtin_popcount(bits) // 켜져있는 비트의 개수
__builtin_ctz(bits) //최하위 비트의 인덱스
(bits & -bits) //최하위 비트의 실제 값
for(int i=bits; i; i=(i-1)&bits) //모든 부분집합 순회

bitset<64> B(42); // ...00101010
string S = B.to_string();
bitset<64> B2("101010");
cout << B2.to_ullong(); // 42

//신발끈 정리 - 변이 교차하지 않는 다각형의 넓이
for(int i=0; i<n; ++i)
	area += X[i]*Y[(i+1)%len] - X[i]*Y[(i+len-1)%len];;
return abs(area/2);

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

//safe hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<ll, int, custom_hash> safe_map;

//safe rand
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
cout << uniform_int_distribution<int>(0, 10)(rng); //return 0,...,10

//파일 입출력
#ifndef ONLINE_JUDGE freopen("a.in","r",stdin); #endif

#파이썬
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
a,b,c = map(int, input().rstrip().split())
