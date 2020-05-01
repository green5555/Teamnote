const int MAX, INF;
struct EdmondKarp{
    struct Edge{
        int next, cap, flow=0;
        Edge* rev;
        Edge(){};
        Edge(int _next, int _cap) : next(_next), cap(_cap) {};
        int remain(){
            return cap - flow;
        }
        void push(int x){
            flow += x;
            rev -> flow -= x;
        }
    };
    vector<Edge*> adj[MAX];
    inline void makeEdge(int u, int v, int cap){
        Edge *uv = new Edge(v, cap), *vu = new Edge(u, 0);
        uv->rev = vu, vu->rev = uv;
        adj[u].push_back(uv);
        adj[v].push_back(vu);
    }
    int maxFlow(int S, int E){
        int total = 0;
        while(true){
            int parent[MAX];
            Edge *path[MAX];
            memset(parent, -1, sizeof(parent));
            queue<int> Q;
            Q.push(S);
            while(!Q.empty()){
                int here = Q.front(); Q.pop();
                for(auto e : adj[here]){
                    int there = e->next;
                    if(e->remain()>0 && parent[there] == -1){
                        Q.push(there);
                        parent[there] = here;
                        path[there] = e;
                        if(there == E) break;
                    }
                }
            }
            if(parent[E] == -1) return total;
            int flow = INF;
            for(int i=E; i!=S; i=parent[i])
                flow = min(flow, path[i]->remain());
            for(int i=E; i!=S; i=parent[i])
                path[i]->push(flow);
            total += flow;
        }
    }
};
