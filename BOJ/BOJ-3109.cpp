#include <bits/stdc++.h>
using namespace std;
char maps[10000][500];
int R,C;
int dy[3] = {1,1,1};
int dx[3] = {-1,0,1};
int ans = 0;

bool dfs(int sx, int sy){
    if(sy == C-1){
        maps[sx][sy] = 'x';
        ans ++;
        return true;
    }
    for(int i=0; i<3; i++){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(nx >=0 && nx < R && ny >= 0 && ny < C && maps[nx][ny] == '.'){
            maps[nx][ny] = 'x';
            if(dfs(nx, ny)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> maps[i][j];
        }
    }

    for(int i=0; i<R; i++){
        //cout << i;
        dfs(i,0);
    }
    cout << ans;
}