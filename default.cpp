#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define _USE_MATH_DEFINES

using namespace std;
using namespace __gnu_pbds;

#define TEST int _tt; cin >> _tt; while (_tt--)
#define all(v) (v).begin(), (v).end()
#define loop(e, v) for (auto& (e) : (v))
#define mem(v, e) memset((v), (e), sizeof(v))
#define _unique(v) (v).erase(unique((v).begin(),(v).end()),(v).end())
#define range(p, xa, xb, ya, yb) ((xa) <= (p).first && (p).first < (xb) && (ya) <= (p).second && (p).second < (yb))
//#define range(v, l, r) ((l) <= (v) && (v) < (r))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char ubyte;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
typedef tuple<int, int, int> tii;
typedef tuple<ll, ll, ll> tll;
typedef tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9+7;

const ll MAX = 1e5+5;
const double EPS = 1e-9;

inline ll ceil(const ll& a, const ll& b) { return (a / b) + !!(a % b); }
inline ll sign(const ll& x) { return (x ? (x < 0 ? -1 : 1) : 0); }
pii operator+ (const pii& a, const pii& b) { return{a.xx+b.xx, a.yy+b.yy}; }
pii operator- (const pii& a, const pii& b) { return {a.xx-b.xx, a.yy-b.yy}; }
inline ll manhattan(const pii& a, const pii& b) { return abs(a.xx-b.xx) + abs(a.yy-b.yy); }
inline int diff(const double& a, const double& b) {
    if (a - EPS < b && b < a + EPS) return 0;
    return (a < b ? -1 : +1);
}

ll N, M, K, Q;
string S, T;

vector<int> arr;

void solve() {
    cin >> N;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    clock_t _st_t = clock();
#endif
    //cout << fixed; cout.precision(10);
    //setfill('0') << setw(4)  // zero padding

    solve();

#ifndef ONLINE_JUDGE
    cerr << endl << endl << (double)(clock() - _st_t)/(double)CLOCKS_PER_SEC << "sec" << endl;
#endif

    return 0;
}