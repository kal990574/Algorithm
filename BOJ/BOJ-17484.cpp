#include <bits/stdc++.h>
using namespace std;
int main(){
    // dp 
    int N, M;
    cin >> N >> M;
    vector<vector<int>> maps(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
        }
    }
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(3, INT_MAX)));
    for(int i=0; i<M; i++){
        for(int j=0; j<3;j++){
            dp[0][i][j] = maps[0][i]; 
        }
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<M; j++){
            if(j!=0){
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + maps[i][j];
            }

            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + maps[i][j];

            if(j != M-1){
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + maps[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<M; i++){
        for(int j=0; j<3; j++){
            ans = min(ans, dp[N-1][i][j]);
        }
    }
    cout << ans << "\n";
}