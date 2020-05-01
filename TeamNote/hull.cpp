vector<Point> convex_hull(vector<Point>& dat) {
	if (dat.size() <= 2) return dat;
	vector<Point> upper, lower;
	sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
		return (a.xx == b.xx) ? a.yy < b.yy : a.xx < b.xx;
	});
	for (const auto& p : dat) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p)
			>= 0) upper.pop_back();
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p)
			<= 0) lower.pop_back();
		upper.emplace_back(p);
		lower.emplace_back(p);
	}
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;
}

//IF int or long long
#define xx first
#define yy second
typedef long long ll;
typedef pair<ll,ll> Point;

inline ll outer(const Point a, const Point b) { //외적
	return a.xx * b.yy - a.yy * b.xx;
}

inline ll ccw(const Point& a, const Point& b, const Point& c) {
	auto tmp = outer({b.xx - a.xx, b.yy - a.yy}, {c.xx - a.xx, c.yy - a.yy});
	return (tmp ? (tmp < 0 ? -1 : 1) : 0);
}

//IF double
struct Point + operator -
diff, outer , ccw