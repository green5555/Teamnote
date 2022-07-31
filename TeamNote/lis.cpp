vector<int> lis(vector<int> v) {
	vector<int> LIS;
	vector<pair<int,int>> path(v.size());
	LIS.push_back(v[0]);
	path[0] = {0, v[0]};
	for(int i=1; i<v.size(); ++i){
		int a = v[i];
		if(LIS.back() < a){
			path[i] = {LIS.size(), a};
			LIS.push_back(a);
			continue;
		}
		auto it = lower_bound(LIS.begin(), LIS.end(), a);
		path[i] = {it-LIS.begin(), a};
		*it = a;
	}
	vector<int> ans;
	for(int i=v.size()-1,pos=LIS.size()-1; pos>=0; --i){
		if(pos == path[i].first){
			ans.push_back(path[i].second);
			--pos;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
