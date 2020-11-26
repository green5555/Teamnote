// s=".a.b.c.d.e." -> m[i] = s[i]가 중심인 '실제' 팰린드롬의 길이
void manacher(const string& s, int m[]) {
    int r = -1, p = -1;
    for (int i=0; i<s.size(); ++i) {
        if (i <= r) m[i] = min((2*p-i>= 0) ? m[2*p-i] : 0, r-i); else m[i] = 0;
        while(i-m[i]-1>=0 && i+m[i]+1<s.size() && s[i-m[i]-1] == s[i+m[i]+1]) ++m[i];
        if (i + m[i] > r) r = i + m[i], p = i;
    }
}