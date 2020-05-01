struct node{
};

const int MAX;
node seg[MAX*4];

node merge(node l, node r){
	//두 노드를 합치기
	//기본 생성자 = 항등원
}

node query(int l, int r, int node, int nodeL, int nodeR){
	if(r < nodeL || nodeR < l) return node();
	if(l <= nodeL && nodeR <=r) return seg[node]; 
	int mid = (nodeL + nodeR)/2;
	return merge(query(l, r, node*2, nodeL, mid), query(l, r, node*2+1, mid+1, nodeR));
}

node update(int index, int value, int node, int nodeL, int nodeR){
	if(index<nodeL || nodeR<index) return seg[node];
	if(nodeL == nodeR)
		return seg[node] = //value로 업데이트 된 값; 
	int mid = (nodeL + nodeR)/2;
	return seg[node] = merge(update(index,value,node*2,nodeL,mid),
							update(index,value,node*2+1,mid+1,nodeR));
}