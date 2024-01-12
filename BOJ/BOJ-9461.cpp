#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> res(N+1);
    for(int i=0; i<N; i++){
        cin >> res[i];
    }
    int mx = *max_element(res.begin(), res.end());
    vector<long long> dp(mx+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<mx+1; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    for(int i=0; i<N; i++){
        cout << dp[res[i]-1] << "\n";
    }
}