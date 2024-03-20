#include <bits/stdc++.h>
using namespace std;
char maps[12][6];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int visited[12][6];
int res = 0;
bool puyo_flag = false;

void bfs(int sx, int sy, char tg){
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    q.push(make_pair(sx, sy));
    v.push_back(make_pair(sx,sy));
    visited[sx][sy] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && !visited[nx][ny] && maps[nx][ny]==tg){
                q.push(make_pair(nx, ny));
                v.push_back(make_pair(nx,ny));
                visited[nx][ny] = 1;
            }
        }
    }

    if(v.size() >= 4){
        for(int i=0; i<v.size(); i++){
            maps[v[i].first][v[i].second] = '.';
        }
        puyo_flag = true;
    }

}

void pop_down(int x, int y, char tg){
    bool flag = true;

    while(flag){
        maps[x][y] = '.';
        if(maps[x+1][y] == '.'){
            maps[x+1][y] = tg;
            x++;
        }
        else {
            maps[x][y] = tg;
            flag = false;
        }
    }
}

int main(){
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin >> maps[i][j];
        }
    }

    while(1){
        // 초기화
        memset(visited, 0, sizeof(visited));
        puyo_flag = false;

        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(maps[i][j] != '.'){
                    bfs(i,j,maps[i][j]);
                }
            }
        }

        for(int i = 11; i>=0; i--){
            for(int j=0; j<6; j++){
                if(maps[i][j] != '.' && maps[i+1][j] == '.'){
                    pop_down(i,j,maps[i][j]);
                }
            }
        }

        if(puyo_flag) res++;
        else break;
    }

    cout << res << "\n";

    return 0;
}