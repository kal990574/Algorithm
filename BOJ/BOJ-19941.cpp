#include <bits/stdc++.h>
using namespace std;
// 그리디 or 슬라이딩 윈도우
int main(){
    int N, K;
    string table;
    int ans = 0;
    cin >> N >> K;
    cin >> table;
    for(int i=0; i<N; i++){
        if(table[i] == 'P'){
            for(int j=i-K; j<=i+K; j++){
                if(j<0 || j>=N) continue;

                if(table[j] == 'H'){
                    table[j] = 'N';
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}