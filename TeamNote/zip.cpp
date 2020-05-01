void zip(vector<ll> &v){
	vector<ll> z;
	for(auto &i : v) z.emplace_back(i);
	sort(z.begin(), z.end());
	z.erase(unique(z.begin(), z.end()), z.end());
	for(auto &i : v) i = lower_bound(z.begin(), z.end(), i) - z.begin();
}
void zip(vector<pll> &v){
	vector<ll> xz, yz;
	for(auto &p : v){xz.emplace_back(p.xx); yz.emplace_back(p.yy);}
	sort(xz.begin(), xz.end()); sort(yz.begin(), yz.end());
	xz.erase(unique(xz.begin(), xz.end()), xz.end());
	yz.erase(unique(yz.begin(), yz.end()), yz.end());
	for(auto &p : v){ p.xx = lower_bound(xz.begin(), xz.end(), p.xx) - xz.begin();
		p.yy = lower_bound(yz.begin(), yz.end(), p.yy) - yz.begin();}
}