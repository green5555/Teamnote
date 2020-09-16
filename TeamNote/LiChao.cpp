const ll INF = -2e18; //최소 y값
struct LiChaoTree{
    struct Line{
        ll a, b;
        ll f(ll x){return a*x+b;}
    };
    struct Node{
        int nl, nr;
        ll xl, xr;
        Line line;
    };
    vector<Node> seg;
    void clear(ll xl, ll xr){//x의 최소, 최대값
        seg.clear();
        seg.push_back({-1, -1, xl, xr, {0, INF}});
    }
    //update(0, v) : 직선 v를 추가한다.
    void update(int no, const Line &v){
        ll xl = seg[no].xl, xr = seg[no].xr, xm = (xl+xr)/2;
        Line lo = seg[no].line, hi = v;
        if(lo.f(xl) > hi.f(xl)) swap(lo, hi);
        //case1 : hi가 언제나 위에 있음
        if(lo.f(xr) <= hi.f(xr)){
            seg[no].line = hi; return;
        }
        //case2 : 왼쪽은 언제나 hi가 위에, 오른쪽에서 lo가 역전함
        if (lo.f(xm) < hi.f(xm)){
            seg[no].line = hi;
            if (seg[no].nr == -1){ //오른쪽에 새로운 노드 할당
                seg[no].nr = seg.size();
                seg.push_back({-1, -1, xm+1, xr, {0, INF}});
            }
            update(seg[no].nr, lo);
        }
        //case 3 : 왼쪽에서 lo가 역전함, 오른쪽은 언제나 lo가 위에
        else{
            seg[no].line = lo;
            if (seg[no].nl == -1){
                seg[no].nl = seg.size();
                seg.push_back({-1, -1, xl, xm, {0, INF}});
            }
            update(seg[no].nl, hi);
        }
    }
    //query(0, x) : f(x)의 최대값은?
    ll query(int no, ll x){
        if (no == -1) return INF;
        ll xl = seg[no].xl, xr = seg[no].xr, xm = (xl+xr)/2;
        if (x <= xm) return max(seg[no].line.f(x), query(seg[no].nl, x));
        else return max(seg[no].line.f(x), query(seg[no].nr, x));
    }
}LCT;
