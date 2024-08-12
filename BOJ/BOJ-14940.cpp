#include <bits/stdc++.h>
using namespace std;
int n,m;
int maps[1001][1001];
int st_x, st_y;
int res[1001][1001];
int visited[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(maps[nx][ny] > 0 && !visited[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = 1;
                res[nx][ny] = res[sx][sy] + 1;
            }
        }
    }
    res[x][y] = 0;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 2){
                st_x = i;
                st_y = j;
            }
        }
    }
    bfs(st_x, st_y);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j] == 1 && res[i][j] == 0) res[i][j] = -1;
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}