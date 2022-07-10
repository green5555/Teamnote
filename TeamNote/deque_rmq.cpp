template<typename T> struct MaxDeque{
    deque<pair<T, int>> q;
    int L=0, R=0;

	bool better(const T &a, const T &b) {
		return a >= b;
	}

    void push(const T &x){
        while(!q.empty() && better(x, q.back().xx)) q.pop_back();
        q.push_back({x, R});
        ++R;
    }
    void pop(){
        if(q.front().yy == L) q.pop_front();
        ++L;
    }
    T get(){ return q.front().xx; }
    int size(){ return R-L+1; }
};