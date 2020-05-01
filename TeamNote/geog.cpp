typedef pair<ll,ll> Point;
Point operator- (const Point &l, const Point &r){
    return {l.xx - r.xx, l.yy - r.yy};
}
inline ll outer(const Point& a, const Point& b) { //외적
    return a.xx * b.yy - a.yy * b.xx;
}
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return outer(b - a, c - a);
}
----------


//실수 좌표를 사용할 경우 eps를 활용하여 수가 같은지 확인해야 한다.
const double eps = 1e-9; //오차 범위
inline int diff(double lhs, double rhs) {//오차 범위 내에서 대소관계
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1 : 1;
}
inline bool is_between(double check, double a, double b) {
	if (a < b) return (a - eps < check && check < b + eps);
	else return (b - eps < check && check < a + eps);
}

struct Point {
	double x, y;
	bool operator==(const Point& rhs) const {
		return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
	}
	Point operator+(const Point& rhs) const {
		return Point{ x + rhs.x, y + rhs.y };
	}
	Point operator -(const Point& rhs) const {
		return Point{ x - rhs.x, y - rhs.y };
	}
	Point operator*(double t) const {
		return Point{ x * t, y * t };
	}
};

struct Line {
	Point pos, dir;
};

inline double inner(const Point& a, const Point& b) { //내적
	return a.x * b.x + a.y * b.y;
}
inline double outer(const Point& a, const Point& b) { //외적
	return a.x * b.y - a.y * b.x;
}

// 1이면 ccw, -1이면 cw, 0이면 일직선상
inline int ccw_line(const Line& line, const Point& point) {
	return diff(outer(line.dir, point - line.pos), 0);
}
inline int ccw(const Point& a, const Point& b, const Point& c) { 
	return diff(outer(b - a, c - a), 0);
}

//점과 점사이 거리
inline double dist(const Point& a, const Point& b) {
	return sqrt(inner(a - b, a - b));
}

inline double dist(const Line& line, const Point& point, bool segment = false) {
    double c1 = inner(point - line.pos, line.dir);
    if (segment && diff(c1, 0) <= 0) return dist(line.pos, point);
    double c2 = inner(line.dir, line.dir);
    if (segment && diff(c2, c1) <= 0) return dist(line.pos + line.dir, point);
    return dist(line.pos + line.dir * (c1 / c2), point);
}