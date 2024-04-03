#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int dp[100001];
int res;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    //dp[1][0] = 0;
    dp[1] = arr[1];
    res = arr[1];
    for(int i=2; i<=n; i++){
        //dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        //dp[i][1] = max(dp[i][0]+arr[i], arr[i]);
        //선택 x
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }
    for(int i=1; i<=n; i++){
        res = max(res, dp[i]);
    }
    cout << res;
}