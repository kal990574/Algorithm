#include <bits/stdc++.h>
using namespace std;
int n,m;
int maps[1001][1001];
int st_x, st_y;
int res[1001][1001];
int visited[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dist = 1;
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
            if(maps[nx][ny] == 1 && !visited[nx][ny]){
                q.push(make_pair(nx,ny));
                res[nx][ny] += dist;
                dist ++;
            }
        }
    }
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
    bfs(st_x,st_y);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}