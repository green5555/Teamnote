typedef pair<ll, ll> Point;
Point operator- (const Point &a, const Point &b){ return {a.xx-b.xx, a.yy-b.yy}; }
inline ll outer(const Point& a, const Point& b) { return a.xx*b.yy - a.yy*b.xx; }
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    ll ret = outer(b - a, c - a); return (ret ? (ret > 0 ? 1 : -1) : 0);
}

Point operator+ (const Point &a, const Point &b){ return {a.xx+b.xx, a.yy+b.yy}; }
Point operator* (const Point &a, const Point &b){ return {a.xx*b.xx, a.yy*b.yy}; }
inline ll get_hypot(const Point& a, const Point& b){ auto c = a-b; return c.xx*c.xx + c.yy*c.yy;}
inline ll inner(const Point& a, const Point& b) { return a.xx*b.xx + a.yy*b.yy; }

inline bool intersect(const pair<Point,Point> &a, const pair<Point,Point> &b){ //직선 a와 b가 교차?
    auto ab = ccw(a.xx, a.yy, b.xx) * ccw(a.xx, a.yy, b.yy);
    auto cd = ccw(b.xx, b.yy, a.xx) * ccw(b.xx, b.yy, a.yy);
    if(!ab && !cd) // a1--b1==a2__b2 or b1--a1==b2__a2
        return (min(b.xx, b.yy) <= max(a.xx, a.yy)) && (min(a.xx, a.yy) <= max(b.xx, b.yy));
    return (ab <= 0) && (cd <= 0);
}

bool angle_cmp(const Point &a, const Point &b){
    if( (Point(0,0) < a) ^ (Point(0,0) < b) ) return a > b;
    return ccw(Point(0,0), a, b) > 0; // 0일때 같은 각도
}

// float
typedef pair<double, double> Point;
Point rotation(const Point &pt, const double &theta){
    double s = sin(theta), c = cos(theta);
    return {c*pt.xx - s*pt.yy, s*pt.xx + c*pt.yy};
}
