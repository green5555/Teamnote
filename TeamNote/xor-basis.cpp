vector<ll> xor_basis(const vector<ll> &v) {
    vector<ll> basis;
    for(auto x : v) {
        for(int j=(int)basis.size()-1; j>=0; j--)
            x = min(x, basis[j]^x);
        if(x) basis.insert(lower_bound(all(basis), x), x);
    }
    reverse(all(basis));
    return basis;
}
