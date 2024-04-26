// 범위 및 조건부 함수를 따로 정의할 것
// range()
// 코드 함수화할 것
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int maps[101][101];
int maps_label[101][101];
int visited[101][101];
int dist[101][101];
int N;
int label = 1;
int res = 10000;

void bfs_label(int x, int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    maps_label[x][y] = label;
    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && maps[nx][ny] == 1){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = 1;
                maps_label[nx][ny] = label;
            }
        }
    }
    label ++;
}

void bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    int s_label = maps_label[x][y];

    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;

    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && maps[nx][ny] == 1 && s_label != maps_label[nx][ny]){
                //cout << nx << " " << ny << "\n";
                res = min(res, dist[sx][sy]);
                return ;
            }
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && maps[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[sx][sy] + 1;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> maps[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && maps[i][j] == 1){
                bfs_label(i,j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));

   //bfs(4,3);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && maps[i][j] == 1){
                bfs(i,j);
            }
        }
    }
    
    cout << res;
    /*
    cout << "\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << maps_label[i][j] << " ";
        }
        cout << "\n";
    }
    */

}