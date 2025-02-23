@ -0,0 +1,83 @@
#include <bits/stdc++.h>
using namespace std;
int N, M;
int maps[51][51];
int visited[51][51];
int dist[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> chik;
int cnt = 0;
int res;

bool chk(int x, int y){
    if(x >= 1 && x<= N && y >=1 && y<=N && !visited[x][y] && maps[x][y] != 2) return true;
    else return false;
}
void check_distance(int x, int y){

}
void bfs(int x, int y){
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    int min_value = 9999;
    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];

            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && maps[nx][ny] == 1 && !dist[nx][ny]){
            //cout << "MM";
            int dis = abs(x-nx) + abs(y-ny);
            min_value += dis;
            //min_value = min(dis, min_value);
            dist[nx][ny] = 1;
            }
            if(chk(nx,ny)){
                //cout << nx << " " << ny << "\n";
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
    chik.push_back(min_value);
    cnt ++;
}
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> maps[i][j];
        }
    }
    /*
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(maps[i][j] == 2){
                check_distance(i,j);
            }
        }
    }
    */
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(maps[i][j] == 2 && !visited[i][j]){
                bfs(i,j);
            }
        }
    }

    for(int i=0; i<chik.size(); i++) cout << chik[i] << " ";
    sort(chik.begin(), chik.end());
    for(int i=0; i<M; i++){
        res += chik[i];
    }
    cout << res;
}