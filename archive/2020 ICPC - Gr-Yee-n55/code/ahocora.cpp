const int MAXN = 100*1000 +1, MAXC = 26; // 트라이 노드 개수, 알파벳 개수
int piv, trie[MAXN][MAXC], fail[MAXN]; //트라이 번호 매기기, 트라이, 실패 함수 링크
bool term[MAXN]; //N번째 트라이가 종말 노드인가?
void init(vector<string> &v){
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(term, 0, sizeof(term));
    piv = 0;
    for(string &i : v){
        int p = 0;
        for(char &j : i){
            if(!trie[p][j-'a']) trie[p][j-'a'] = ++piv;
            p = trie[p][j-'a'];
        }
        term[p] = 1;
    }
    queue<int> que;
    for(int i=0; i<MAXC; i++)
        if(trie[0][i]) que.push(trie[0][i]);
    while(!que.empty()){
        int x = que.front(); que.pop();
        for(int i=0; i<MAXC; i++){
            if(trie[x][i]){
                int p = fail[x];
                while(p && !trie[p][i]) p = fail[p];
                p = trie[p][i];
                fail[trie[x][i]] = p;
                if(term[p]) term[trie[x][i]] = 1;
                que.push(trie[x][i]);
            }
        }
    }
}
bool query(string &s){
    int p = 0;
    for(char &i : s){
        while(p && !trie[p][i-'a']) p = fail[p];
        p = trie[p][i-'a'];
        if(term[p]) return 1;
    }
    return 0;
}