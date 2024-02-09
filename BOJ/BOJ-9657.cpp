#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    for(int i=6; i<=n; i++){
        if(dp[i-1] == 2 || dp[i-3] == 2 || dp[i-4] == 2) dp[i] = 1;
        else dp[i] = 2;
    }
    if(dp[n] == 1) cout << "SK";
    else cout << "CY";

}