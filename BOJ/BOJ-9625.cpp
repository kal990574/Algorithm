#include <bits/stdc++.h>
using namespace std;
int k;
int a,b;
vector<pair<int, int> > dp(46);
int main(){
    cin >> k;
    dp[1].first = 0;
    dp[1]. second = 1;
    for(int i=2; i<=k; i++){
        dp[i].second = dp[i-1].first + dp[i-1].second;
        dp[i].first = dp[i-1].second;
    }
    cout << dp[k].first << " " << dp[k].second;
}