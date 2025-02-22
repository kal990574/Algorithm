#include <bits/stdc++.h>
using namespace std;
int R, C;
char maps[21][21];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ans = 1;
void dfs(int x, int y, vector<int>& visited, int cnt){
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<R && ny>=0 && ny<C && !visited[maps[nx][ny] - 'A']){
            visited[maps[nx][ny] - 'A'] = 1;
            //cout << nx << " " << ny << "\n";
            dfs(nx,ny,visited, cnt + 1);
            ans = max(cnt + 1, ans);
            visited[maps[nx][ny] - 'A'] = 0;
        }
    }
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        string str;
        cin >> str;
        for(int j=0; j<C; j++){
            maps[i][j] = str[j];
        }
    }
    vector<int> visited(26);
    visited[maps[0][0] - 'A'] = 1;
    dfs(0,0, visited, 1);
    cout << ans << "\n";
}