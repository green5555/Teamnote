// Integer & Float
typedef pair<geom_t, geom_t> Point;
Point operator- (const Point &a, const Point &b){ return {a.xx-b.xx, a.yy-b.yy}; }
inline geom_t outer(const Point& a, const Point& b) { return a.xx*b.yy - a.yy*b.xx; }

Point operator+ (const Point &a, const Point &b){ return {a.xx+b.xx, a.yy+b.yy}; }
Point rot45(Point p) { return {p.xx+p.yy, p.yy-p.xx}; }
inline geom_t inner(const Point& a, const Point& b) { return a.xx*b.xx + a.yy*b.yy; }
inline geom_t sign(const geom_t& x) { return (x ? x / abs(x) : 0); }
inline geom_t euclid2(const Point& a, const Point& b) { 
    Point ret = a - b;
    return ret.xx*ret.xx + ret.yy*ret.yy;
} //a와 b의 직선 거리
inline geom_t manhattan(const Point& a, const Point& b) { 
    Point ret = a - b;
    return abs(ret.xx) + abs(ret.yy);
} //a와 b의 택시 거리
struct Line {
    Point st, ed;
};
bool angle_cmp(const Point &a, const Point &b){
   if( (Point(0,0) < a) ^ (Point(0,0) < b) ) return a > b;
   return ccw(Point(0,0), a, b) > 0; // 0일때 같은 각도
}


// Integer Geometry
typedef geom_t ll
inline ll ccw(const Point& a, const Point& b, const Point& c) { return outer(b - a, c - a); }
inline bool intersect(const Line &a, const Line &b){ 
    auto ab = sign(ccw(a.st, a.ed, b.st)) * sign(ccw(a.st, a.ed, b.ed));
    auto cd = sign(ccw(b.st, b.ed, a.st)) * sign(ccw(b.st, b.ed, a.ed));
    if(!ab && !cd) // c a-b d 혹은 a c-d b
        return (min(b.st, b.ed) <= max(a.st, a.ed)) &&
                (min(a.st, a.ed) <= max(b.st, b.ed));
    return (ab <= 0) && (cd <= 0);
} //직선 a와 b가 교차? (정수)


// Float Geometry
typedef geom_t double
const double EPS = 1e-9; //const ld LEPS = 1e-16;
inline int diff(double lhs, double rhs) { 
    if (lhs - EPS < rhs && rhs < lhs + EPS) return 0;
    return (lhs < rhs) ? -1 : 1;
} //실수 lhs < rhs
inline bool is_between(double check, double a, double b) { 
    if (a < b) return (a - EPS < check && check < b + EPS);
    else return (b - EPS < check && check < a + EPS);
} //실수 a < check < b
inline sign(double x) { return diff(x, 0); }
inline int ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b - a, c - a), 0);
}

// Equation Geomentry (with Float)
double norm(Point p) { return sqrt(p.xx*p.xx + p.yy*p.yy); }
Point rot90(Point p) { return {-p.yy, p.xx}; }
struct Circle {
    Point cp; double r;
};
pair<int, Point> intersect(Circle c1, Circle c2) {
    Point p1 = c1.cp, p2 = c2.cp;
    double r1 = c1.r, r2 = c2.r;
    Point lineVec = p2 - p1;
    double L = norm(lineVec);
    if (L > r1 + r2) { // no-intersection
        return {0, {0, 0}};
    } else if (L <= abs(r1 - r2)) { // include
        return {-1, {0, 0}};
    }
    double x = (r1 * r1 - r2 * r2 + L * L) / (2 * L);
    Point mp = p1 + lineVec * (x / L);
    double y = sqrt(r1 * r1 - x * x);
    if (y <= 0) { // meet 1
        return {1, {mp, mp}};
    } else { // meet 2
        return { 2, {
            mp + rot90(lineVec) * (y / L),
            mp - rot90(lineVec) * (y / L)
        }};
    }
}
pair<int, Point> intersect(Line ln, Circle cc) {
    Point lineVec = ln.p2 - ln.p1;
    double a = inner(lineVec, lineVec);
    double b = 2 * inner(lineVec, ln.p1 - cc.cp);
    double c = inner(cc.cp, cc.cp) + inner(ln.p1, ln.p1) - 2 * inner(cc.cp, ln.p1) - cc.r * cc.r;
    const auto D = b*b - 4*a*c;
    if (sign(D) < 0) { // no-intersection
        return {0, {0, 0}};
    } else if (sign(D) == 0) { // meet 1
        double ret = -b / (2 * a);
        return {1, {ret, ret}};
    } else { // meet 2
        double ret1 = (-b + sqrt(D)) / (2 * a);
        double ret2 = (-b - sqrt(D)) / (2 * a);
        if (ret1 > ret2) swap(ret1, ret2);
        return {2, {ret1, ret2}};
    }
}
bool incLine(Line ln, vector<Circle> &cir) {
    vector<pair<ld, int>> pene;
    pene.emplace_back(0, 0); // Segment start-point
    pene.emplace_back(1, 0); // Segment end-point
    for(auto &c : cir) {
        Circle tmp = c;
        tmp.r += (EPS * tmp.r);
        auto ret = intersect(ln, tmp);
        if (ret.xx == 2) {
            pene.emplace_back(ret.yy.xx, -1);
            pene.emplace_back(ret.yy.yy, 1);
        }
    }
    sort(all(pene)); // Through the line
    int depth = 0;
    bool flag = false;
    for(auto &s : pene) {
        depth -= s.yy;
        if (s.yy == 0) flag = !flag; // Line segment start or end
        if (flag && depth <= 0) return false;
    }
    return true;
}

// ax+b (with Integer Geometry)
struct Form {
    // y = (dir)x + intY
    ld dir, intY;
    int flag; // 0: normal, 1: vertical, 2: horizon
    Form() {}
    Form(const Line& ln) {
        // y1 - y2 = dir(x1 - x2)
        // dir = (y1 - y2) / (x1 - x2)
        if (diff(ln.st.xx, ln.ed.xx) == 0) {
            intY = ln.st.xx;
            flag = 1;
        } else if (diff(ln.st.yy, ln.ed.yy) == 0) {
            intY = ln.st.yy;
            flag = 2;
        } else {
            dir = (ln.st.yy - ln.ed.yy) / (ln.st.xx - ln.ed.xx);
            intY = ln.st.yy - dir * ln.st.xx;
            flag = 0;
        }
    }
    bool assn(Point pp) {
        switch (flag) {
            case 0: return diff(pp.yy, dir*pp.xx + intY) == 0;
            case 1: return diff(pp.xx, intY) == 0;
            case 2: return diff(pp.yy, intY) == 0;
        }
    }
};
pair<bool, Point> intersect(Form f1, Form f2) {
    if (f1.flag > f2.flag) swap(f1, f2);
    int flag = (1 << f1.flag) + (1 << (f2.flag + 3));
    switch (flag) {
        case 18:
        case 36: {
            // vertical & vertical   // horizon & horizon
            return {!diff(f1.intY, f2.intY), {f1.intY, f2.intY}};
        }
        case 34: {
            // vertical & horizon
            return {true, {f1.intY, f2.intY}};
        }
        case 17: {
            // normal & vertical
            return {true, {
                f2.intY,
                f1.dir * f2.intY + f1.intY // assign
                }};
        }
        case 33: {
            // normal & horizon
            // (y-c)/d = x
            return {true, {
                (f2.intY - f1.intY) / f1.dir, // assign
                f2.intY
                }};
        }
        case 9: break;  // normal & normal
    }
    if (diff(f1.dir, f2.dir) == 0) { // parallel
        return {diff(f1.intY, f2.intY) == 0, {f1.intY, f2.intY}};
    }
    Point ret;
    // (d1 - d2)x + (c1 - c2) = 0
    // x = (c2 - c1) / (d1 - d2)
    assert(diff(f1.dir, f2.dir));
    ret.xx = (f2.intY - f1.intY) / (f1.dir - f2.dir);
    ret.yy = f1.dir * ret.xx + f1.intY;
    return {true, ret};
}