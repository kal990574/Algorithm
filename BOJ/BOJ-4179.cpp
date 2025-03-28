#include <bits/stdc++.h>
using namespace std;
// 불 먼저 이후 지훈
// main -> while()문 -> jh_bfs() -> fire_bfs() -> exit
int R,C;
vector<vector<char> > maps(1000, vector<char>(1000));
vector<vector<int> > visited1(1000, vector<int>(1000));
vector<vector<int> > visited2(1000, vector<int>(1000));
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<pair<int, int>, int> > jq;
queue<pair<pair<int, int>, int> > fq;
int res = 1000000;
int fin = 0;

void jh_bfs(){
    int ori_cnt = jq.front().second;
    do{
        int sx = jq.front().first.first;
        int sy = jq.front().first.second;
        int cnt = jq.front().second;
        // visited1[sx][sy] = 1;
        jq.pop();

        if(maps[sx][sy] == 'F') continue;

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];

            if(nx<0 || nx>=R || ny <0 || ny >=C){
                res = min(res, cnt);
                fin = 1;
                break;
            }

            if(visited1[nx][ny]) continue;
            
            if(maps[nx][ny] == '.'){
                jq.push(make_pair(make_pair(nx,ny), cnt+1));
                visited1[nx][ny] = 1;
            }
        }
    }while(!jq.empty() && jq.front().second == ori_cnt);
}

void fire_bfs(){
    int ori_cnt = fq.front().second;
    do{
        int sx = fq.front().first.first;
        int sy = fq.front().first.second;
        int cnt = fq.front().second;
        // visited2[sx][sy] = 1;
        fq.pop();

        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];

            if(nx<0 || nx>=R || ny <0 || ny >=C) continue;

            if(visited2[nx][ny]) continue;

            if(maps[nx][ny] == 'J'){
                maps[nx][ny] = 'F';
                fq.push(make_pair(make_pair(nx,ny), cnt + 1));
                visited2[nx][ny] = 1;
            }

            if(maps[nx][ny] == '.'){
                fq.push(make_pair(make_pair(nx,ny), cnt+1));
                maps[nx][ny] = 'F';
                visited2[nx][ny] = 1;
            }
        }
    }while(!fq.empty() && fq.front().second == ori_cnt);
}

int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'J'){
                jq.push(make_pair(make_pair(i,j), 0));
                visited1[i][j] = 1;
            }
            if(maps[i][j] == 'F'){
                fq.push(make_pair(make_pair(i, j), 0));
                visited2[i][j] = 1;
            }
        }
    }

    while(1){
        fin = 0;
        if(!jq.empty()) jh_bfs();
        if(!fq.empty()) fire_bfs();

        if(fin == 1 || jq.empty()){
            break;
        }
    }
    if(res == 1000000) cout << "IMPOSSIBLE\n";
    else cout << res+1 << "\n";
}