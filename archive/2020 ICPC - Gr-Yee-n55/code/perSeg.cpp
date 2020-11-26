const int MAX = 100100;
struct Node{
    int v = 0; //반드시 항등원
    Node *left = 0, *right = 0;
};
vector<Node*> Tree;
void init(){
    Tree.clear();
    Tree.push_back(new Node());
}
void make_tree(int i, int v){
    Tree.push_back(make_tree(Tree.back(), i, v, 0, MAX-1));
}
Node* make_tree(Node *prev, int i, int v, int nl, int nr){
    Node *now = new Node();
    if(i < nl || nr < i) return prev;
    if (nl == nr) {
        now->v = prev->v + v;
        return now;
    }
    int mid = (nl + nr) / 2;
    if (!prev->left) 
        prev->left = new Node(), prev->right = new Node();
    now->left = make_tree(prev->left, i, v, nl, mid);
    now->right = make_tree(prev->right, i, v, mid+1, nr);
    now->v = now->left->v + now->right->v;
    return now;
}
int query(int root_i, int l, int r){
    return query(Tree[root_i], l, r, 0, MAX-1);
}
int query(Node *here, int l, int r, int nl, int nr){
    if(here == 0) return 0;
    if(nr < l || r < nl) return 0;
    if(l <= nl && nr <= r) return here -> v;
    int mid = (nl + nr)/2;
    return query(here->left, l, r, nl, mid) +
            query(here->right, l, r, mid+1, nr);
}
for(int i=0; i<size_of_x; ++i) PST.make_tree(p.yy, 1);