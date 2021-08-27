const int MAX = 111;
const int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int vst[MAX][MAX];
bool valid(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    //check board? if(b[x][y] == 'X') return 0;
    return 1;
}
void bfs2(int sx, int sy){
    memset(vst, -1, sizeof(vst));
    vst[sx][sy] = 0;
    queue<pii> q;
    q.emplace(sx, sy);
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int d=0; d<4; ++d){
            int nx = x+dir[d][0], ny = y+dir[d][1];
            if(!valid(nx, ny)) continue;
            if(vst[nx][ny] == -1){
                vst[nx][ny] = vst[x][y]+1;
                q.emplace(nx, ny);
            }
        }
    }
}
