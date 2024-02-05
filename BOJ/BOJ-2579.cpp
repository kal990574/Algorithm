#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    if(n == 1) cout << v[0];
    else if(n == 2) cout << v[0]+v[1];
    else {
        vector<vector<int> > dp(n, vector<int>(2));
        dp[0][0] = v[0];
        dp[0][1] = 0;
        dp[1][0] = dp[0][0] + v[1];
        dp[1][1] = v[1];
        for(int i=2; i<n; i++){
            dp[i][0] = v[i] + dp[i-1][1];
            dp[i][1] = max(v[i] + dp[i-2][0], v[i] + dp[i-2][1]);
        }
        int res = 0;
        res = max(dp[n-1][0], dp[n-1][1]);
        cout << res;
    }
}