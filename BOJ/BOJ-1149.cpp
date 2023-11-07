#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int dp[1003][3];
    int RGB[1003][3];
    for(int i=0; i<N; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }
    dp[0][0] = RGB[0][0];
    dp[0][1] = RGB[0][1];
    dp[0][2] = RGB[0][2];

    for(int i=1; i<N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + RGB[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + RGB[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + RGB[i][2];
    }
    cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}