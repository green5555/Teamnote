//사용 금지 : 벡터 재할당
const int MAX = 100100;
struct PersistentSegmentTree{
	struct Node{
		int value = 0; //반드시 항등원
		Node *left = 0, *right = 0;
	};
	vector<Node*> Tree;
	void init(){
		Tree.clear();
		Tree.push_back(new Node());
	}
	void make_tree(int idx, int value){
		Tree.push_back(make_tree(Tree.back(), idx, value, 0, MAX-1));
	}
	Node* make_tree(Node *prev, int idx, int value, int nodeL, int nodeR){
		Node *now = new Node();
		if(idx < nodeL || nodeR < idx) return prev;
		if (nodeL == nodeR) {
			now->value = prev->value + value;
			return now;
		}
		int mid = (nodeL + nodeR) / 2;
		if (!prev->left) 
			prev->left = new Node(), prev->right = new Node();
		now->left = make_tree(prev->left, idx, value, nodeL, mid);
		now->right = make_tree(prev->right, idx, value, mid+1, nodeR);
		now->value = now->left->value + now->right->value;
		return now;
	}
	int query(int root_idx, int l, int r){
		return query(Tree[root_idx], l, r, 0, MAX-1);
	}
	int query(Node *here, int l, int r, int nodeL, int nodeR){
		if(here == 0) return 0;
		if(nodeR < l || r < nodeL) return 0;
		if(l <= nodeL && nodeR <= r) return here -> value;
		int mid = (nodeL + nodeR)/2;
		return query(here->left, l, r, nodeL, mid) + query(here->right, l, r, mid+1, nodeR);
	}
};
for(int i=0; i<size_of_x; ++i)
    PST.make_tree(p.yy, 1);
