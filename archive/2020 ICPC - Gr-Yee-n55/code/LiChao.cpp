struct Line{ ll a, b; ll f(ll x){return a*x+b;} };
struct Node{ int nl, nr; ll xl, xr; Line line; };
vector<Node> seg;
void clear(ll xl, ll xr){//x의 최소, 최대값
    seg.clear();
    seg.push_back({-1, -1, xl, xr, {0, INF}});
}

void update(int no, const Line &v){ //update(0, v) : 직선 v 추가
    ll xl = seg[no].xl, xr = seg[no].xr, xm = (xl+xr)/2;
    Line lo = seg[no].line, hi = v;
    if(lo.f(xl) > hi.f(xl)) swap(lo, hi); // f(nl)의 값이 hi가 크다.
    if(lo.f(xr) <= hi.f(xr)){ //1) hi가 언제나 위
        seg[no].line = hi; return;
    }
    if (lo.f(xm) < hi.f(xm)){//2) 오른쪽에서 lo가 역전
        seg[no].line = hi;
        if (seg[no].nr == -1){ //오른쪽에 새 노드
            seg[no].nr = seg.size();
            seg.push_back({-1, -1, xm+1, xr, {0, INF}});
        }
        update(seg[no].nr, lo);
    }
    else{//3) 왼쪽에서 lo가 역전
        seg[no].line = lo;
        if (seg[no].nl == -1){ //왼쪽에 새 노드
            seg[no].nl = seg.size();
            seg.push_back({-1, -1, xl, xm, {0, INF}});
        }
        update(seg[no].nl, hi);
    }
}
ll query(int no, ll x){ //query(0, x) : f(x)의 최대값은?
    if (no == -1) return INF;
    ll xl = seg[no].xl, xr = seg[no].xr, xm = (xl+xr)/2;
    if (x <= xm) return max(seg[no].line.f(x), query(seg[no].nl, x));
    else return max(seg[no].line.f(x), query(seg[no].nr, x));
}