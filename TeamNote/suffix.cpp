//NlogNlogN
vector<int> getSA(string &str){
	vector<int> ret(str.size()), rank(str.size()+1, -1), newRank(str.size()+1);
	for(int i=0; i<str.size(); ++i){
		ret[i] = i;
		rank[i] = str[i];
	}
	for(int pivot=1; pivot<str.size(); pivot<<=1){
		sort(ret.begin(), ret.end(), [&](const int &a, const int &b){
			if(rank[a] != rank[b]) return rank[a]<rank[b];
			return rank[a+pivot] < rank[b+pivot];
		});
		newRank[ret[0]] = 0;
		newRank[str.size()] = -1;
		for(int i=1; i<str.size(); ++i)
			newRank[ret[i]] = newRank[ret[i-1]] + (rank[ret[i-1]] != rank[ret[i]] || rank[ret[i-1]+pivot] != rank[ret[i]+pivot]);
		rank = newRank;
	}
	return ret;
}

// calculates suffix array. O(n*logn)
typedef char T;
vector<int> suffix_array(const vector<T>& in) {
	int n = (int)in.size(), c = 0;
	vector<int> temp(n), pos2bckt(n), bckt(n), bpos(n), out(n);
	for (int i = 0; i < n; i++) out[i] = i;
		sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
	for (int i = 0; i < n; i++) {
		bckt[i] = c;
		if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
	}
	for (int h = 1; h < n && c < n; h <<= 1) {
	for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
	for (int i = n - 1; i >= 0; i--) bpos[bckt[i]] = i;
	for (int i = 0; i < n; i++)
		if (out[i] >= n - h) temp[bpos[bckt[i]]++] = out[i];
	for (int i = 0; i < n; i++)
		if (out[i] >= h) temp[bpos[pos2bckt[out[i] - h]]++] = out[i] - h;
	c = 0;
	for (int i = 0; i + 1 < n; i++) {
		int a = (bckt[i] != bckt[i + 1]) || (temp[i] >= n - h)
				|| (pos2bckt[temp[i + 1] + h] != pos2bckt[temp[i] + h]);
		bckt[i] = c;
		c += a;
		}
		bckt[n - 1] = c++;
		temp.swap(out);
	}
	return out;
}
// calculates lcp array. it needs suffix array & original sequence. O(n)
vector<int> lcp(const vector<T>& in, const vector<int>& sa) {
	int n = (int)in.size();
	if (n == 0) return vector<int>();
	vector<int> rank(n), height(n - 1);
	for (int i = 0; i < n; i++) rank[sa[i]] = i;
	for (int i = 0, h = 0; i < n; i++) {
		if (rank[i] == 0) continue;
		int j = sa[rank[i] - 1];
		while (i + h < n && j + h < n && in[i + h] == in[j + h]) h++;
		height[rank[i] - 1] = h;
		if (h > 0) h--;
	}
		return height;
}