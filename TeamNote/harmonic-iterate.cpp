// O(sqrt(n))
ll n = 10000;

for(ll l=1,r; l<=n; l=r+1){
    r=n/(n/l);
    cout << l << '~' << r << " : n/i = " << n/l << endl;
}
