struct DequeMin{
    deque<pii> q;
    int i=0, j=0;

    void push(int x){
        while(!q.empty() && q.back().xx >= x) q.pop_back();
        q.push_back({x, j});
        ++j;
    }
    void pop(){
        if(q.front().yy == i) q.pop_front();
        ++i;
    }
    int get(){
        return q.front().xx;
    }
}minq;

struct DequeMax{
    deque<pii> q;
    int i=0, j=0;

    void push(int x){
        while(!q.empty() && q.back().xx <= x) q.pop_back();
        q.push_back({x, j});
        ++j;
    }
    void pop(){
        if(q.front().yy == i) q.pop_front();
        ++i;
    }
    int get(){
        return q.front().xx;
    }
}maxq;

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
