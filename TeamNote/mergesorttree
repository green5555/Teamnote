const int MAX = 100000;
int arr[MAX];
vector<int> seg[MAX*4+1];
void init(int l, int r, int no){
	if(l==r){ seg[no].push_back(arr[l]); return; }
	int mid = (l+r)/2;
	init(l,mid,no*2), init(mid+1,r,no*2+1);
	auto &left = seg[no*2], &right = seg[no*2+1];
	merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(seg[no]));
}
//구간 [l:r]에서 value보다 큰 원소의 개수를 리턴한다.
int query(int value, int l, int r, int no, int nl, int nr){
	if(r<nl || nr<l) return 0;
	if(l <= nl && nr <= r)
		return seg[no].end() - upper_bound(seg[no].begin(), seg[no].end(), value);
	int mid = (nl + nr)/2;
	return query(value,l,r,no*2,nl,mid)+query(value,l,r,no*2+1,mid+1,nr);
}
