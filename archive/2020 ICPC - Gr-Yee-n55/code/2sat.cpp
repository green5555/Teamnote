const int MAX=10010*2; // (변수 개수)*2 [반드시 짝수]
//여기에 "SCC"를 넣으세요!! (struct 없이)
vector<int> solve() {
    make_SCC(MAX);
    for (int i = 0; i < MAX; i += 2)
        if (sccn[i] == sccn[i + 1])
            return vector<int>();
    vector<int> ans(MAX / 2, -1);
    int arr[MAX];
    for (int i = 0; i < MAX; ++i) arr[i] = i;
    sort(arr, arr + MAX, [&](int &a, int &b) {
        if (sccn[a] != sccn[b]) return sccn[a] > sccn[b];
        return a < b;
    });
    for (int i = 0; i < MAX; ++i)
        if (ans[arr[i] / 2] == -1)
            ans[arr[i] / 2] = !(arr[i] & 1);
    return ans;
}
void makeEdge(int X, bool XisTrue, int Y, bool YisTrue) {
    adj[2 * X + !XisTrue].push_back(2 * Y + YisTrue);
    adj[2 * Y + !YisTrue].push_back(2 * X + XisTrue);
}
