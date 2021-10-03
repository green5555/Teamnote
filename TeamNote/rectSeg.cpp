struct RectSeg {	// 직사각형들의 넓이를 관리하는 웰논 세그 (boj.kr/3392)
    ll cnt[MAX*4], rng[MAX*4], diff[MAX*4];
    ll init(vector<ll> &zip, int no, int nl, int nr) {    // 압축한 좌표를 토대로, 노드 사이 실제 차이를 계산
        if (nl == nr) return diff[no] = zip[nl] - zip[nl-1];    // 0~1 --> 1
        int mid = (nl + nr)/2;
        return diff[no] = init(zip,no*2,nl,mid) + init(zip,no*2+1,mid+1,nr);
    }
    void prop(int no, int nl, int nr) {
        if (cnt[no] > 0) rng[no] = diff[no]; // colored: return self's width
        else {  // uncolored: just merge childs
            if (nl != nr) rng[no] = rng[no*2] + rng[no*2+1];
            else rng[no] = 0;
        }
    }
    ll query(int l, int r, int no, int nl, int nr) {
        if (r < nl || nr < l) return 0ll;
        if (l <= nl && nr <= r) return rng[no];
        int mid = (nl+nr)/2;
        return query(l, r, no*2, nl, mid) + query(l, r, no*2+1, mid+1, nr);
    }
    void update(int l, int r, int v, int no, int nl, int nr) {
        if (r < nl || nr < l) return;
        if (l <= nl && nr <= r) {
            cnt[no] += v;
            prop(no, nl, nr); return;
        }
        int mid = (nl+nr)/2;
        update(l, r, v, no*2, nl, mid); update(l, r, v, no*2+1, mid+1, nr);
        prop(no, nl, nr);
    }
} RS;

// = main ========================

    RS.init(yzip, 1, 1, N-1);
    RS.query(1, N-1, 1, 1, N-1);
    RS.update(r.xx+1, r.yy, (r.flag?-1:+1), 1, 1, N-1);