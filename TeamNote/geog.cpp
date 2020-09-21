typedef pair<ll, ll> Point;
Point operator- (const Point &a, const Point &b){ return {a.xx-b.xx, a.yy-b.yy}; }
inline ll outer(const Point& a, const Point& b) { return a.xx*b.yy - a.yy*b.xx; }
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    ll ret = outer(b - a, c - a); return (ret ? (ret > 0 ? 1 : -1) : 0);
}

Point operator+ (const Point &a, const Point &b){ return {a.xx+b.xx, a.yy+b.yy}; }
inline ll inner(const Point& a, const Point& b) { return a.xx*b.xx + a.yy*b.yy; }

inline bool intersect(const pair<Point,Point> &a, const pair<Point,Point> &b){ //직선 a와 b가 교차?
    auto ab = ccw(a.xx, a.yy, b.xx) * ccw(a.xx, a.yy, b.yy);
    auto cd = ccw(b.xx, b.yy, a.xx) * ccw(b.xx, b.yy, a.yy);
    if(!ab && !cd) // c a-b d 혹은 a c-d b
        return (min(b.xx, b.yy) <= max(a.xx, a.yy)) && (min(a.xx, a.yy) <= max(b.xx, b.yy));
    return (ab <= 0) && (cd <= 0);
}

bool angle_cmp(const Point &a, const Point &b){
    if( (Point(0,0) < a) ^ (Point(0,0) < b) ) return a > b;
    return ccw(Point(0,0), a, b) >= 0; // 0일때 같은 각도
}
