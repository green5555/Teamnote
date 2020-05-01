double ternary (double S, double E) {
    for(int i=0;i<100;i++) {
        double L = (2*S+E)/3, R = (S+2*E)/3;
        if(f(L) < f(R)) S = L;
        else E = R;
    }
    return value(S);
}

//대안 : 기울기로 이분 탐색
int ternary (int S, int E) {
    int ret = 0x7fffffff;
    while(S+3<E) {
        int L = (2*S+E)/3, R = (S+2*E)/3;
        if(f(L) < f(R)) S = L;
        else E = R;
    }
    for(int i=S;i<=E;i++) {
        ret = min(ret, f(i));
    }
    return ret;
}