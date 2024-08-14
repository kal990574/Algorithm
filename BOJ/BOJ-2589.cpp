#include <bits/stdc++.h>
using namespace std;
int L, W;
char maps[51][51];
int visited[51][51];
int dist[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int max_dist;
vector<int> v;
void bfs(int x, int y){
    queue<pair<int, int> > q;
    for(int i=0; i<L; i++){
        for(int j=0; j<W; j++){
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(maps[nx][ny] == 'L' && !visited[nx][ny] && nx >= 0 && nx < L && ny >= 0 && ny < W){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[sx][sy] + 1;
                max_dist = max(max_dist, dist[nx][ny]);
            }
        }
    }
    v.push_back(max_dist);
}
int main(){
    cin >> L >> W;
    v.push_back(0);
    for(int i=0; i<L; i++){
        for(int j=0; j<W; j++){
            cin >> maps[i][j];
        }
    }
    for(int i=0; i<L; i++){
        for(int j=0; j<W; j++){
            if(maps[i][j] == 'L'){
                bfs(i,j);
            }
        }
    }
    cout << *max_element(v.begin(), v.end());
}