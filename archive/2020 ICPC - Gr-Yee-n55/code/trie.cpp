 const int MAXN = 100*1000 +1, MAXC = 10; // 트라이 노드 개수, 알파벳 개수
int cnt, trie[MAXN][MAXC]; //트라이 번호 매기기, 트라이 노드
bool term[MAXN]; //N번째 트라이가 종말 노드인가?
void clear(){
    memset(trie, 0, sizeof(trie));
    memset(term, 0, sizeof(term));
    cnt = 0;
}
void insert(string &x){
    int here = 0;
    for(char &i : x){
        if(!trie[here][i-'0']) trie[here][i-'0'] = ++cnt;
        here = trie[here][i-'0'];
    }
    term[here] = 1;
}
bool query(string &x){
    int here = 0;
    for(char &i : x){
        if(!trie[here][i-'0']) return 0;
        here = trie[here][i-'0'];
        if(term[here]) return 1;
    }
    return 0;
}