const int MAX;

struct node{
	// TODO
	// 기본 생성자 = 항등원.
};

node seg[MAX*4];

node merge(node l, node r){
	// TODO
}

node query(int l, int r, int no, int nl, int nr){
	if(r < nl || nr < l) return node();
	if(l <= nl && nr <=r) return seg[no]; 
	int mid = (nl + nr)/2;
	return merge(query(l, r, no*2, nl, mid), query(l, r, no*2+1, mid+1, nr));
}

void update(int i, node v, int no, int nl, int nr){
	if(i<nl || nr<i) return;
	if(nl == nr) {
        seg[no] = v; //TODO : seg[no]에 v를 업데이트.
        return;
    }
	int mid = (nl + nr)/2;
    update(i,v,no*2,nl,mid), update(i,v,no*2+1,mid+1,nr);
	seg[no] = merge(seg[no*2], seg[no*2+1]);
}