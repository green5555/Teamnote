deque<pii> q; //{value, idx}
for(int i=0; i<n; ++i){
    int a = v[i];
	while(!q.empty()){
		if(q.back().xx >= a) q.pop_back();
		else break;
	}
	while(!q.empty()){
		if(q.front().yy < i-m+1) q.pop_front();
		else break;
	}
	q.emplace_back(a, i);
	cout << q.front().xx << ' ';
}