ll C(ll i, ll j){
}
void solve_dnc(int i, int l, int r, int optl, int optr){
    if (l > r) return;
    int mid = (l + r)/2;
    pll best = {LLONG_MAX, -1};
    for (int k = optl; k <= min(mid, optr); k++)
        best = min(best, {dp[i-1][k] + C(k+1, mid), k});
    dp[i][mid] = best.first;
    solve_dnc(i, l, mid - 1, optl, best.second);
    solve_dnc(i, mid + 1, r, best.second, optr);
}
