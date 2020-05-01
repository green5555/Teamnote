vector<int> rabin_karp(string const& pat, string const& text) {
    const int B = 31; 
    const int M = 1e9 + 9;
    int P = pat.size(), T = text.size();

    //P_pow[i] = (P^i)%M
    vector<ll> p_pow(max(P, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * B) % M;

    //H[i] = Hash(text[0...i-1])
    vector<ll> H(T + 1, 0); 
    for (int i = 0; i < T; i++)
        H[i+1] = (H[i] + (text[i] - 'a' + 1) * p_pow[i]) % M; 
    
    // hv = Hash(pat)
    ll hv = 0; 
    for (int i = 0; i < P; i++) 
        hv = (hv + (pat[i] - 'a' + 1) * p_pow[i]) % M; 

    vector<int> matched;
    for (int i = 0; i + P - 1 < T; i++) { 
        ll cur_h = (H[i+P] + M - H[i]) % M; 
        if (cur_h == hv * p_pow[i] % M)
            matched.push_back(i);
    }
    return matched;
}