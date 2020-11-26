const int MAX, INF; //MAX = 정점의 개수, INF = 최대 용량
int level[MAX], work[MAX];
struct Edge{
	int next, cap, flow=0; Edge* rev;
	Edge(){};
	Edge(int _next, int _cap) : next(_next), cap(_cap) {};
};
vector<Edge*> adj[MAX];
inline void make_edge(int u, int v, int cap){
	Edge *uv = new Edge(v, cap), *vu = new Edge(u, 0);
	uv->rev = vu, vu->rev = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
//싱크까지 도달 가능한 레벨 그래프를 생성 할 수 있는가?
bool bfs(int S, int E){
    memset(level, -1, sizeof(level));
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int here = Q.front(); Q.pop();
        for(auto &i : adj[here]){
            int there = i->next;
            //레벨이 정해지지 않고, 남은 용량이 있는 간선인가?
            if(level[there] == -1 && i->cap >0){
                level[there] = level[here]+1;
                Q.push(there);
            }
        }
    }
    return (level[E] != -1);
}
//here에서 E에 도달할 때 까지 flow 만큼 흘려보내본다.
//싱크까지 얼마나 유량을 흘릴 수 있었는지 리턴한다.
int dfs(int here, int flow, int E){
    if(here == E) return flow;
    int size = adj[here].size();
    for(int &i = work[here]; i<size; ++i){
        int there = adj[here][i]->next, c = adj[here][i]->cap;
        if(level[here]+1 == level[there] && c >0){
            int nc = dfs(there, min(flow, c), E);
            if(nc){
                adj[here][i]->cap -= nc;
                adj[here][i]->rev->cap += nc;
                return nc;
            }
        }
    }
    return 0;
}
int maxflow(int S, int E){
    int total = 0;
    while(bfs(S,E)){
        memset(work, false, sizeof(work));
        while(true){
            int flow = dfs(S, INF, E);
            if(flow == 0) break;
            total += flow;
        }
    }
    return total;
}