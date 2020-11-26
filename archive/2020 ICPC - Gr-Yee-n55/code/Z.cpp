vector<int> Zalgorithm(string &S) {
	int n = S.size(), l=0, r=0;
	vector<int> Z(n);
	for (int i = 1; i < n; i++) {
		if (i > r) {
		    l = r = i;
			while (r < n && S[r - l] == S[r]) r++;
			Z[i] = r - l; r--;
		}
		else {
			int k = i - l;
			if (Z[k] < r - i + 1) Z[i] = Z[k];
			else {
				l = i;
				while (r < n && S[r - l] == S[r]) r++;
				Z[i] = r - l; r--;
			}
		}
	}
	return Z;
}
