#include <bits/stdc++.h>
using namespace std;
int N,M;
int start_x, start_y;
int direction;
int maps[51][51];
int clean_cnt = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool range(int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < M) return true;
    else return false;
}

int change_dir(int dir){
    dir--;
    if(dir == -1) dir = 3;
    return dir;
}

int back_dir(int dir){
    int back;
    back = dir-2;
    if(back == -2) back = 2;
    if(back == -1) back = 3;
    return back;
}

void clean(int sx, int sy, int dir){
    int flag = 0;
    if(range(sx,sy) && maps[sx][sy] == 0){
        maps[sx][sy] = 2;
        clean_cnt ++;
        //cout << sx << " " << sy << "\n";
    }

    for(int i=0; i<4; i++){
        if(range(sx+dx[i], sy+dy[i]) && maps[sx+dx[i]][sy+dy[i]] == 0){
            flag++;
            dir = change_dir(dir);
            if(range(sx+dx[dir], sy+dy[dir]) && maps[sx+dx[dir]][sy+dy[dir]] == 0){
                clean(sx+dx[dir], sy+dy[dir], dir);
                return ;
            }
            else {
                clean(sx,sy,dir);
                return ;
            }
        }
    }

    if(!flag){
        int back = back_dir(dir);
        if(range(sx+dx[back], sy+dy[back]) && maps[sx+dx[back]][sy+dy[back]] != 1) {
            clean(sx+dx[back],sy+dy[back], dir);
            return ;
        }
        if(range(sx+dx[back], sy+dy[back]) && maps[sx+dx[back]][sy+dy[back]] == 1) return ;
    }
}

int main(){
    cin >> N >> M;
    cin >> start_x >> start_y >> direction;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
        }
    }
    clean(start_x, start_y, direction);
    cout << clean_cnt;
}