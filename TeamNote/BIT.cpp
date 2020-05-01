const int MAX;
struct BIT{
	int seg[MAX+1] = {};
	int query(int idx){
		int ret = 0;
		while(idx > 0){
			ret += seg[idx];
			idx -= idx & -idx;
		}
		return ret;
	}
	void update(int idx, int a){
		while(idx <= MAX){
			seg[idx] += a;
			idx += idx & -idx;
		}
	}
	int kth(int k){
		int ret = 0;
		for(int i=30; i>=0; --i){
			int pivot = ret + (1<<i);
			if(pivot <= MAX && seg[pivot] < k){
				k -= seg[pivot];
				ret = pivot;
			}
		}
		return ret+1;
    }
};