const int MAX;
int parent[MAX];
void clear(){ memset(parent, -1, sizeof(parent));}
int find(int a){ 
    if(parent[a]<0) return a; return parent[a] = find(parent[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b); if(a==b) return;
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a]; parent[a] = b;
}