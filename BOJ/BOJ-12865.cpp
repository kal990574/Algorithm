#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int> > v(n+1, vector<int>(2));
    vector<vector<int> > dp(n+1, vector<int>(k+1));
    for(int i=1; i<=n; i++){
        cin >> v[i][0] >> v[i][1];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(v[i][0] <= j){
                dp[i][j] = max(dp[i-1][j], v[i][1] + dp[i-1][j-v[i][0]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
}