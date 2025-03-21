#include <bits/stdc++.h>
using namespace std;
int N, K;
const int MOD = 1000000000;
int dp[201][201] = {0};
int main(){
    cin >> N >> K;
    for(int i=0; i<=N; i++){
        dp[1][i] = 1;
    }
    // dp[K][N]
    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    
    cout << dp[K][N] % MOD << "\n";
}