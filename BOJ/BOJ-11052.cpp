#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> card(n+1);
    vector<int> dp(n+1);
    for(int i=1; i<n+1; i++){
        cin >> card[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + card[j]);
        }
    }
    cout << dp[n];
}