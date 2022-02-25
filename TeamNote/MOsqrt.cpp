int n, ans[MAX];
vector<pair<pii,int>> query;
inline void add(int k){//현 구간에 k를 하나 추가해준다.
	//do something : ex) if(++cnt[k] == 1) ++ret;
}
inline void pop(int k){//현 구간에서 k를 하나 제거해준다.
	//do something : ex) if(--cnt[k] == 0) --ret;
}
void MOquery(){
	const int sqrtN = sqrt(n);
	sort(query.begin(), query.end(), [sqrtN](auto &a, auto &b){
		int Ln = a.first.first/sqrtN, Rn = b.first.first/sqrtN;
		if(Ln != Rn) return Ln < Rn;
		//부등호를 뒤집으면 더 빨리질수도 있음.
		if(Ln&1) return a.first.second > b.first.second;
        	else return a.first.second < b.first.second;
	});

	int L = 1, R = 1; add(1); // 1-based?
	for(auto &P : query){
		int nL = P.first.first, nR = P.first.second;
		if(nL < L) for(int i=L-1; i>=nL; --i) add(i);
		if(R < nR) for(int i=R+1; i<=nR; ++i) add(i);
		if(L < nL) for(int i=L; i<nL; ++i) pop(i);
		if(nR < R) for(int i=R; i>nR; --i) pop(i);
		L = nL; R = nR; ans[P.second] = ret;
	}
}
