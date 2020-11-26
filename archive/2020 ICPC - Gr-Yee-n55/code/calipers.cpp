//+ 정수 컨벡스 헐
void calipers(vector<point>& pt) {
	sort(pt.begin(), pt.end(), [](const point& a, const point& b) {
		return (a.xx == b.xx) ? a.yy < b.yy : a.xx < b.xx;
	});
	vector<point> up, lo;
	for (const auto& p : pt) {
		while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0)
		    up.pop_back();
		while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) 
		    lo.pop_back();
		up.emplace_back(p);
		lo.emplace_back(p);
	}
	for (int i = 0, j = (int)lo.size() - 1; i + 1 < up.size() || j > 0; ) {
		// DO WHAT YOU WANT with up[i], lo[j]
		if (i + 1 == up.size()) --j;
		else if (j == 0) ++i;
		else if ((ll)(up[i+1].yy-up[i].yy)*(lo[j].xx-lo[j-1].xx)
			> (ll)(up[i+1].xx-up[i].xx)*(lo[j].yy-lo[j-1].yy)) ++i;
		else  --j;
	}
}