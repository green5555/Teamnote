const int MAX = 100001;

vector<int> adj[MAX];
int dfsn, dfsl[MAX], dfsr[MAX];
void make_tree(int here, int parent){
    dfsl[here] = dfsr[here] = dfsn++;
    for(int &there : adj[here]){
        if(there == parent) continue;
        make_tree(there, here);
        dfsr[here] = max(dfsr[here], dfsr[there]);
    }
}
