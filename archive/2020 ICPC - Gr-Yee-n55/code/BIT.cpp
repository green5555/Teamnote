const int MAX;
int seg[MAX+1] = {};
int query(int i){
	int ret = 0;
	while(i > 0){ ret += seg[i]; i -= i & -i;}
	return ret;
}
void update(int i, int a){
	while(i <= MAX){ seg[i] += a; i += i & -i;}
}
int kth(int k){
	int ret = 0;
	for(int i=30; i>=0; --i){
		int pivot = ret + (1<<i);
		if(pivot <= MAX && seg[pivot] < k){
			k -= seg[pivot]; ret = pivot;
		}
	}
	return ret+1;
}