bool isPrime(ll x) {
    if(x <= 1) return 0;
    if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(ll i=3; i*i<=x; i+=2)
        if(x%i == 0)
            return 0;
    return 1;
}

// fl is not sorted
void factorize(ll n, vector<ll>& fl) {
    fl.clear();
    for(ll i=2; i*i<=n; ++i)
        while(n % i == 0) {
            fl.push_back(i);
            fl /= i;
        }
    if(n > 1) fl.push_back(n);
}