#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int main(){
    cin >> T;
    while(T){
        int c[21] = {0, };
        int dp[10001] = {0, };
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> c[i];
        }
        cin >> M;
        // 1 2 2 3
        dp[0] = 1;
        for(int i=0; i<N; i++){
            for(int j=c[i]; j<=M; j++){
                dp[j] += dp[j-c[i]];
            }
        }
        cout << dp[M] << "\n";
        T--;
    }
}