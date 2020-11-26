const int MAX = 1000010, base = 257, m = 1e9+7;
vector<ll> ppow;
void init(){
    ppow.resize(MAX);
    ppow[0] = 1;
    for(int i=1; i<MAX; ++i)
        ppow[i] = (ppow[i - 1] * base) % m;
}
void hash(vector<ll> &h, string &s){
    h.clear(); h.resize(s.size()+1);
    for(int i=0; i<s.size(); ++i)
        h[i+1] = (h[i] + (s[i]+1) * ppow[i]) % m;
}
inline ll get(vector<ll> &h, int l, int len){
    return (h[l+len] - h[l] + m) % m;
}
bool compare(vector<ll> &h1, int l1, vector<ll> &h2, int l2, int len){
    ll v1 = get(h1, l1, len), v2 = get(h2, l2, len);
    if(l1 < l2) v1 = (v1 * ppow[l2 - l1]) % m;
    if(l1 > l2) v2 = (v2 * ppow[l1 - l2]) % m;
    return v1 == v2;
}