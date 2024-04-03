#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int c[101];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=c[i]; j<=k; j++){
            dp[j] += dp[j - c[i]];
        }
    }
    cout << dp[k];
}