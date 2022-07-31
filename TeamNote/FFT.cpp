typedef complex<double> base;
struct FFT{
    void fft(vector<base> &a, bool inv){
        int n = a.size(), j = 0;
        vector<base> roots(n/2);
        for(int i=1; i<n; i++){
            int bit = (n >> 1);
            while(j >= bit){
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if(i < j) swap(a[i], a[j]);
        }
        double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
        for(int i=0; i<n/2; i++){
            roots[i] = base(cos(ang * i), sin(ang * i));
        }
        for(int i=2; i<=n; i<<=1){
            int step = n / i;
            for(int j=0; j<n; j+=i){
                for(int k=0; k<i/2; k++){
                    base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                    a[j+k] = u+v;
                    a[j+k+i/2] = u-v;
                }
            }
        }
        if(inv) for(int i=0; i<n; i++) a[i] /= n;
    }

    /*
    [1] 2^k가 될 때 까지 v와 w를 채운다.
    [2] w를 reverse 시킨다
    [3] ret[i] = w의 back이 i에 위치하도록 shift 했을 때의 sum(v[i]*w[i])
    */
    void multiply(const vector<ll> &v, const vector<ll> &w, vector<ll> &ret){
        vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
        int n = 2; while(n < v.size() + w.size()) n <<= 1;
        fv.resize(n); fw.resize(n);
        fft(fv, 0); fft(fw, 0);
        for(int i=0; i<n; i++) fv[i] *= fw[i];
        fft(fv, 1);
        ret.clear(); ret.resize(n);
        for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    }
};

// 높은 정확도
void multiply_big(vector<ll> &v, vector<ll> &w, vector<ll> &ret){
    int n = 2; while(n < v.size() + w.size()) n <<= 1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for(int i=0; i<v.size(); i++){
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for(int i=0; i<w.size(); i++){
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1, 0);
    fft(v2, 0);
    for(int i=0; i<n; i++){
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
    }
    fft(r1, 1);
    fft(r2, 1);
    ret.clear(); ret.resize(n);
    for(int i=0; i<n; i++){
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        ret[i] = (av << 30) + (bv << 15) + cv;
    }
}


/*******************************/
// 예전 코드
void fft(vector <complex<double>> &a, bool invert){
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        complex<double> wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            complex<double> w(1);
            for (int j=0;j<len/2;j++){
                complex<double> u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
void multiply(const vector<int> &a,const vector<int> &b, vector<int> &ret){
    vector <complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max((int)a.size(),(int)b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    ret.resize(n);
    for (int i=0;i<n;i++) ret[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}
