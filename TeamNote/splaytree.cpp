const int MAX = 1000010;
struct splay_tree{
    struct node{
        node *l=0, *r=0, *p=0;
        int key; int sz = 1;
        node(){}
        node(int _key) : key(_key){};
        node(int _key, node *_p) : key(_key), p(_p){};
        ~node(){if(l) delete l; if(r) delete r;}

        ll value=0, sum=0, lazy=0;
        //초기값 배정 : key = [1~n]에 대해 호출됨
        void init(){
            value = sum = a[key];
        }

        //현재 노드의 정보를 자식으로부터 갱신
        void pull(){ 
            sz = 1;
            sum = value;
            for(node *c : {l, r}){
                if(!c) continue;
                sz += c->sz;
                sum += c->sum;
            }
        }

        //현재 노드에 v 라는 업데이트가 들어왔다.
        //현재 노드의 값들을 갱신하고, lazy에 태깅.
        void update(ll v){
            value += v;
            sum += sz * v;
            lazy += v;
        }

        //lazy를 자식에게 뿌려준다.
        //자식을 타고 내려갈 때 마다 (혹은 심심할 때) 호출 되어야 함.
        void prop(){
            if(lazy == 0) return;
            for(node *c : {l, r}){
                if(!c) continue;
                c->update(lazy);
            }
            lazy = 0;
        }
    } *root;

    node *ptr[MAX];

    // 1-n을 인덱스로 value[1-n] 초기화, 0과 n+1에 더미노드.
    void clear(int n){
        if(root) delete root;
        node *x = root = new node(0);
        for(int i=1; i<=n; ++i){
            ptr[i] = x->r = new node(i, x);
            x = x->r;
            x->init();
        }
        x->r = new node(n+1, x);
        for(int i=n; i>=1; --i) ptr[i]->pull();
        splay(ptr[(n+1)/2]);
    }

    //x를 부모로 올린다.
    void rotate(node *x) {
        node *p = x->p, *b;
        p->prop(); x->prop();
        if (x == p->l) {
            p->l = b = x->r; x->r = p;
        } else {
            p->r = b = x->l; x->l = p;
        }
        x->p = p->p; p->p = x;
        if (b) b->p = p;
        (x->p ? p == x->p->l ? x->p->l : x->p->r : root) = x;
        p->pull(); x->pull();
    }

    //x를 루트로 만든다.
    //if(g) : x를 g의 자식으로 붙인다.
    void splay(node *x, node *g = 0){
        while(x->p != g){
            node* p = x->p;
            if(p->p == g){
                rotate(x); break;
            }
            auto pp = p->p;
            if((p->l == x) == (pp->l == p)){
                rotate(p); rotate(x);
            }else{
                rotate(x); rotate(x);
            }
        }
        if(!g) root = x;
    }

    // 1-based K번째 원소를 루트로 만든다. (더미가 있을시)
    void kth(int k) {
        node *x = root;
        x->prop();
        while (1) {
            while (x->l && x->l->sz > k){
                x = x->l; x->prop();
            }
            if (x->l) k -= x->l->sz;
            if (!k--) break;
            x = x->r; x->prop();
        }
        splay(x);
    }

    //[l~r]을 (r+1의 왼쪽 서브트리에) 모은다.
    node *range(int l, int r){
        kth(r+1);
        node *R = root;
        kth(l-1);
        splay(R, root);
        return root->r->l;
    }

    void update_range(int l, int r, ll v){
        range(l,r)->update(v);
    }

    ll query_range(int l, int r){
        return range(l,r)->sum;
    }

    void _print(node *x, int depth){
        if(x == 0) return;
        _print(x->l, depth+1);
        cout << string(depth, '-');
        cout << x->key << " : " << x->value << ' '  << x->sum << ' ' << x->lazy << endl;
        _print(x->r, depth+1); 
    }
    void print(){
        #ifdef ONLINE_JUDGE
        return;
        #endif
        cout << "*** print ***" << endl; _print(root,1); cout << endl;}
}s;
