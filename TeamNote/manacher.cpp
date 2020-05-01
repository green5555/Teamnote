void manacher(const string& s, int m[]) {
    int r = -1, p = -1;
    for (int i=0; i<s.size(); ++i) {
        if (i <= r) m[i] = min((2*p-i>= 0) ? m[2*p-i] : 0, r-i); else m[i] = 0;
        while(i-m[i]-1>=0 && i+m[i]+1<s.size() && s[i-m[i]-1] == s[i+m[i]+1]) ++m[i];
        if (i + m[i] > r) r = i + m[i], p = i;
    }
}