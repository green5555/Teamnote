//최근 m개의 최소값
for(int i=0; i<n; ++i){
	int a; cin >> a;
	while(!Q.empty()){
		if(Q.back().xx >= a) Q.pop_back();
		else break;
	}
	while(!Q.empty()){
		if(Q.front().yy < i-m+1) Q.pop_front();
		else break;
	}
	Q.emplace_back(a, i);
	cout << Q.front().yy << ' ';
}