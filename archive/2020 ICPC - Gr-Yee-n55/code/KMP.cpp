void KMP(string &text, string &pat){
    vector<int> fail(pat.size(), 0);
    //pat과 pat끼리 KMP를 실행한다
    for(int i=1, match=0; i<pat.size(); ++i){
        while(match && pat[i] != pat[match])
            match = fail[match-1];
        if(pat[i] == pat[match])
            fail[i] = ++match;
    }
    for(int i=0, match=0; i<text.size(); ++i){
        while(match && text[i] != pat[match])// 매칭 중에 불일치 발생
            match = fail[match-1]; //맞았었던 부분의 실패함수 적용
        if(text[i] == pat[match]) //한 글자 매칭 성공
            if(++match == pat.size()){//완전 매칭 성공
                cout << "match at " << (i-match+1);
                match = fail[match-1];
            }
    }
}