const int MAX;
struct UnionFind{
    int p[MAX];
    void clear(){
        memset(p, -1, sizeof(p));
    }
    UnionFind(){clear();}
    int find(int a){
        if(p[a]<0) return a;
        return p[a] = find(p[a]);
    }
    void merge(int a, int b){
        a = find(a), b = find(b);
        if(a==b) return;
        if(p[a] < p[b]) swap(a,b);
        p[b] += p[a]; p[a] = b;
    }
}uf;
