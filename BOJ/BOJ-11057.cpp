#include <algorithm>
#include <iostream>
using namespace std;
#define MOD 10007

int main() {
    int N;
    cin >> N;
    long long dp[1002][10] = {0,};
    long long res = 0;
    for(int i=0; i<10; i++) dp[1][i] = 1;
    for(int i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
            dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }
    for(int i=0; i<10; i++){
        res = (res + dp[N][i]);
    }
    res %= MOD;
    cout << res << "\n";
}