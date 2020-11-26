int visit[MAX];
bool haveCycle(int here){
	if(visit[here]) return visit[here] == -1;
	visit[here] = -1;
	for(int &there : adj[here]) if(haveCycle(there)) return true;
	visit[here] = 1; return false;
}
memset(visit, -1, sizeof(visit));