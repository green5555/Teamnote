// O(sqrt(x))
ll x = 10000;

for(ll l=1,r; l<=x; l=r+1){
    r=x/(x/l);
    cout << l << '~' << r << " : x/i = " << x/l << exdl;
}
