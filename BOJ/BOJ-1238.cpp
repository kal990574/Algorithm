#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int>> map(N+1, vector<int>(N+1, 1e9));
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(i == X) continue;
        ans = max(ans, map[i][X] + map[X][i]);
    }
    cout << ans;
}