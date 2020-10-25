//아래로 볼록 (최소값): >, 위로 볼록 (최대값) : <
ll l=0, r=n-1;
while(l+3<=r) {
    ll x = (2*l+r)/3, y = (l+2*r)/3;
    if(f(x) > f(y)) l = x; 
    else r = y;
}
ll ans = INT_MAX;
for(int i=l; i<=r; ++i) ans = min(ans, f(i));

//실수는 while 대신 for(int i=0;i<100;i++)
