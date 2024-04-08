#include <bits/stdc++.h>
using namespace std;
int dp[31];
int arr[31];
int N;
int main(){
    cin >> N;
    // 3*N, 1*2 2*1
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=N; i+=2){
        dp[i] = dp[i-2] * dp[2];
        for(int j=4; j<=i; j+=2){
            dp[i] += dp[i-j] * 2;
        }
    }
    cout << dp[N];
}