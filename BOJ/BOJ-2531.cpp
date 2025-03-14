#include <bits/stdc++.h>
using namespace std;
int N, d, k, c;
int main(){
    // 1억회 2억 5600만 bytes
    // K개씩 슬라이딩 윈도우
    // 가짓수 활용??
    // 쿠폰번호가 반드시 K개에 묶일 때 ?
    // 시계방향 회전
    // N 접시 개수, d 초밥 가짓수, k 윈도우 크기, c 쿠폰번호
    cin >> N >> d >> k >> c;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    int cnt[3001] = {0};
    int kind = 0;
    int max_kind = 0;
    for(int i=0; i<k; i++){
        if(cnt[v[i]] == 0) kind ++;
        cnt[v[i]] ++;
    }
    
    max_kind = max(max_kind, kind);
    for(int i=0; i<N; i++){
        cnt[v[i]] --;
        if(cnt[v[i]] == 0) kind --;

        if(cnt[v[(i+k)%N]] == 0) kind ++;
        cnt[v[(i+k)%N]] ++;

        if(cnt[c] == 0) max_kind = max(max_kind, kind + 1);
        else max_kind = max(max_kind, kind);
    }
    cout << max_kind << "\n";
}