#include <bits/stdc++.h>
using namespace std;
// 0 ~ N까지 정수 K개를 더해서 N을 만듬
// 순서 바뀌면 다른 경우
// DP
// 2억회, 1억 2800만 bytes
// dp[i][j], i: 개수, j:목표값
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
            if(j==0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    
    cout << dp[K][N] % MOD << "\n";
}