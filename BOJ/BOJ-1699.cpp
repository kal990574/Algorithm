#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(){
    int n;
    cin >> n;
    // 1 2 3 
    // 1 2 3 4 2 
    // 1 2 3 4 2 3 4
    // 1
    int dp[MAX+1];
    for(int i=0; i<=n; i++){
        dp[i] = i;
        for(int j=1; j*j <= i; j++){
            dp[i] = min(dp[i - j*j]+1, dp[i]);
        }
    }
    cout << dp[n];
}