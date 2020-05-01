//dp[i] = min{b[j]*a[i] + c[j]}+d[i]; j<i, b[j]는 비증가/비감소
const int MAX=100000;
struct ConvexHullTrick{
	int s=0, e=0, idx[MAX];
	pll deq[MAX]; //first * x + second
	double cross(int a, int b) {
		return 1.0 * (deq[a].yy - deq[b].yy) / (deq[b].xx - deq[a].xx);
	}
	void insert(pll v,int line_idx){//current line , i
		deq[e] = v;
		idx[e] = line_idx;
		while(s+1<e && cross(e - 2, e - 1) > cross(e - 1, e)){
			deq[e-1] = deq[e];
			idx[e-1] = idx[e];
			e--;
		}
		e++;
	}
	ll query(long long x){  // query가 증가수열일 경우
		//그래프 = └ 꼴 (>=), ┌ 꼴 (<=)
		while(s+1<e && deq[s+1].yy - deq[s].yy <= x * (deq[s].xx - deq[s+1].xx))
			s++;
		return deq[s].xx*x+deq[s].yy; //idx[s]
	}
	ll query2(long long x){ // 일반 query
		int l = 0, r = e - 1;
		while (l != r) {
			int m = (l + r) / 2;
			if (cross(m, m + 1) <= x) l = m + 1;
			else r = m;
		}
		return deq[l].xx*x+deq[l].yy; //idx[l]
	}
	void clear(){s = e = 0;}
} CHT;

//Line Container
//https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
// ax + b 꼴의 직선들에 대해 최대값 구한다. logN
// 최소값을 원하면, 기울기에 -1을 곱해 x축 대칭 시킨다.
// 실수 사용을 원하면, inf = 1/.0, div(a,b) = a/b
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll a, ll b) {
		auto z = insert({a, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
}CHT;
