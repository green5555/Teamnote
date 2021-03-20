void make_lr(int a, int b, pii p){
    int l = p.xx, r = p.xx+p.yy;
    lsum += l;
    f.make_edge(S2, b, l);
    f.make_edge(a, E2, l);
    f.make_edge(a, b, r-l);
}

make_flow(E1, S1, 2e9);
if(maxflow(S2, E2) < lsum) {cout << "impossible";}
cout << maxflow(S1, E1);
