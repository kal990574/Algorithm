#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > dp(n, vector<int>(3));
    vector<int> v;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    dp[0][2] = 0;
    for(int i=1; i<n; i++){
        dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + v[i];
        dp[i][2] = dp[i-1][1] + v[i];
    }
    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}