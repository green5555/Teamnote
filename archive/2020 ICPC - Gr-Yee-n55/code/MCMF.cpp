const int MAX, INF; //MAX = 최대 정점 개수, INF = 가중치의 최장거리
struct MinCostMaxFlow{
    struct Edge{
        int next, cap, cost, flow=0;
        Edge* rev;
        Edge(){};
        Edge(int _next, int _cap, int _cost) : next(_next), cap(_cap), cost(_cost) {};
        int remain(){
            return cap - flow;
        }
        void push(int x){
            flow += x;
            rev -> flow -= x;
        }
    };
    vector<Edge*> adj[MAX];
    inline void makeEdge(int u, int v, int cap, int cost){
        Edge *uv = new Edge(v, cap, cost), *vu = new Edge(u, 0, -cost);
        uv->rev = vu, vu->rev = uv;
        adj[u].push_back(uv);
        adj[v].push_back(vu);
    }
    pair<int,int> MCMF(int S, int E){
        int minCost = 0, maxFlow = 0;
        while(true){
            int parent[MAX], dist[MAX];
            Edge *path[MAX];
            queue<int> Q;
            bool inQ[MAX] = {};
            memset(parent, -1, sizeof(parent));
            fill(dist, dist+MAX, INF);
            dist[S] = 0;
            Q.push(S);
            inQ[S] = true;
            while(!Q.empty()){
                int here = Q.front(); Q.pop();
                inQ[here] = false;
                for(auto e : adj[here]){
                    int there = e->next;
                    if(e->remain()>0 && dist[there] > dist[here]+e->cost){
                        dist[there] = dist[here] + e->cost;
                        parent[there] = here;
                        path[there] = e;
                        if(!inQ[there]){
                            Q.push(there);
                            inQ[there] = true;
                        }
                    }
                }
            }
            if(parent[E] == -1) break;
            int flow = INF;
            for(int i=E; i!=S; i=parent[i])
                flow = min(flow, path[i]->remain());
            for(int i=E; i!=S; i=parent[i]){
                minCost += flow * path[i]->cost;
                path[i]->push(flow);
            }
            maxFlow += flow;
        }

        return {minCost, maxFlow};
    }
}F;