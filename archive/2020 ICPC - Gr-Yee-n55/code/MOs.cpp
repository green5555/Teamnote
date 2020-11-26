int n, ans[MAX];
vector<pair<pii,int>> query;
inline void add(int k){//현 구간에 k를 하나 추가해준다.
	//do something : ex) if(++cnt[k] == 1) ++ret;
}
inline void pop(int k){//현 구간에서 k를 하나 제거해준다.
	//do something : ex) if(--cnt[k] == 0) --ret;
}

int sqrtN = sqrt(n);
sort(query.begin(), query.end(), [](auto &a, auto &b){
	//L/sqrt(N)이 동일한 쿼리를 한 버킷에
	int Ln = a.first.first/sqrtN, Rn = b.first.first/sqrtN;
	if(Ln != Rn) return Ln < Rn;
	return a.first.second < b.first.second;
});

//[0,0]부터 시작해 스위핑 해주자.
int L = 0, R = 0; add(arr[0]);
for(auto &P : query){
	int nL = P.first.first, nR = P.first.second;
	//1. L을 nL로 바꿔주기.
	if(L < nL){ //오른쪽으로 밀면서 [L, nL) 제거
		for(int i=L; i<nL; ++i)
			pop(arr[i]);
	}
	else{ //왼쪽으로 밀면서 추가 [nL, L) 추가
		for(int i=L-1; i>=nL; --i)
			add(arr[i]);
	}
	//2. R을 nR로 바꿔주기.
	if(R < nR){//오른쪽으로 밀면서 (R, nR] 추가
		for(int i=R+1; i<=nR; ++i)
			add(arr[i]);
	}
	else{//왼쪽으로 밀면서 (nR, R] 제거
		for(int i=R; i>nR; --i)
			pop(arr[i]);
	}
	//구간, 쿼리의 답 업데이트
	L = nL; R = nR; ans[P.second] = ret;
}
