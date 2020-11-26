const int MAXA, MAXB;
int A[MAXA], B[MAXB];
bool visit[MAXA];
vector<int> adj[MAXA];
bool DFS(int here){
    if(visit[here]) return false;
    visit[here] = true;
    for(int &there : adj[here])
        if(B[there] == -1 || DFS(B[there])){
            A[here] = there, B[there] = here;
            return true;
        }
    return false;
}
int biMatch(){
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int match = 0;
    for(int i=0; i<MAXA; ++i)
        if(A[i] == -1){
            memset(visit, 0, sizeof(visit));
            match += DFS(i);
        }
    return match;
}
