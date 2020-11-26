//아래로 볼록 (최소값): >, 위로 볼록 (최대값) : <
int l=0, r=n-1;
while(l+3<=r) { //실수는 이 부분을 반복문으로
    int x = (2*l+r)/3, y = (l+2*r)/3;
    if(f(x) > f(y)) l = x; 
    else r = y;
}
int ans = INT_MAX;
for(int i=l; i<=r; ++i) ans = min(ans, f(i));
