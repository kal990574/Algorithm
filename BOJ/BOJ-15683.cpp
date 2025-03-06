#include <bits/stdc++.h>
using namespace std;
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int> > maps(8, vector<int>(8));
vector<vector<int> > c_maps(8, vector<int>(8));
void change1(int x, int y, int idx){
    while(1){
        x += dx[idx];
        y += dy[idx];
        if(x<0 || x>=N || y<0 || y>=M) break;
        else{
            if(maps[x][y] == 6) break;
            if(maps[x][y] == 0) c_maps[x][y] = 7;
        }
    }
}
void change2(int x, int y, int idx1, int idx2){
    //cout << idx1 << idx2 << "\n";
    int x1 = x;
    int y1 = y;
    while(1){
        x1 += dx[idx1];
        y1 += dy[idx1];
        if(x1<0 || x1>=N || y1<0 || y1>=M) break;
        else{
            if(maps[x1][y1] == 6) break;
            if(maps[x1][y1] == 0) c_maps[x1][y1] = 7;
        }
    }
    int x2 = x;
    int y2 = y;
    while(1){
        x2 += dx[idx2];
        y2 += dy[idx2];
        if(x2<0 || x2>=N || y2<0 || y2>=M) break;
        else{
            if(maps[x2][y2] == 6) break;
            if(maps[x2][y2] == 0) c_maps[x2][y2] = 7;
        }
    }
}
void change3(int x, int y, int idx1, int idx2){
    int x1 = x;
    int y1 = y;
    while(1){
        x1 += dx[idx1];
        y1 += dy[idx1];
        if(x1<0 || x1>=N || y1<0 || y1>=M) break;
        else{
            if(maps[x1][y1] == 6) break;
            if(maps[x1][y1] == 0) c_maps[x1][y1] = 7;
        }
    }
    int x2 = x;
    int y2 = y;
    while(1){
        x2 += dx[idx2];
        y2 += dy[idx2];
        if(x2<0 || x2>=N || y2<0 || y2>=M) break;
        else{
            if(maps[x2][y2] == 6) break;
            if(maps[x2][y2] == 0) c_maps[x2][y2] = 7;
        }
    }
}
void change4(int x, int y, int idx1, int idx2, int idx3){
    int x1 = x;
    int y1 = y;
    while(1){
        x1 += dx[idx1];
        y1 += dy[idx1];
        if(x1<0 || x1>=N || y1<0 || y1>=M) break;
        else{
            if(maps[x1][y1] == 6) break;
            if(maps[x1][y1] == 0) c_maps[x1][y1] = 7;
        }
    }
    int x2 = x;
    int y2 = y;
    while(1){
        x2 += dx[idx2];
        y2 += dy[idx2];
        if(x2<0 || x2>=N || y2<0 || y2>=M) break;
        else{
            if(maps[x2][y2] == 6) break;
            if(maps[x2][y2] == 0) c_maps[x2][y2] = 7;
        }
    }
    int x3 = x;
    int y3 = y;
    while(1){
        x3 += dx[idx3];
        y3 += dy[idx3];
        if(x3<0 || x3>=N || y3<0 || y3>=M) break;
        else{
            if(maps[x3][y3] == 6) break;
            if(maps[x3][y3] == 0) c_maps[x3][y3] = 7;
        }
    }
}
void change5(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x;
        int ny = y;
        while(1){
            nx += dx[i];
            ny += dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) break;
            else{
                if(maps[nx][ny] == 6) break;
                if(maps[nx][ny] == 0) c_maps[nx][ny] = 7;
            }
        }
    }
}
void f1(int x, int y, int num){
    vector<int> dir_cnt(4, 0);
    for(int i=0; i<4; i++){
        int nx = x;
        int ny = y;
        while(1){
            //cout << "#";
            nx += dx[i];
            ny += dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) break;
            if(nx >= 0 && nx < N && ny >=0 && ny < M){
                if(maps[nx][ny] == 6){
                    break;
                }
                if(maps[nx][ny] == 0){
                    dir_cnt[i] ++;
                }
            }
        }
    }
    //cout << dir_cnt[0];
    //cout << dir_cnt[1];
    //cout << dir_cnt[2];
    //cout << dir_cnt[3];
    //cout << "\n";
    if(num == 1){
        int mx = max_element(dir_cnt.begin(), dir_cnt.end()) - dir_cnt.begin();
        change1(x,y,mx);
        //cout << mx << "\n";
    }

    if(num == 2){
        if(dir_cnt[0] + dir_cnt[2] > dir_cnt[1] + dir_cnt[3]){
            change2(x,y,0,2);
        }
        else{
            change2(x,y,1,3);
        }
    }
    if(num == 3){
        vector<int> d(4, 0);
        d[0] = dir_cnt[0] + dir_cnt[1];
        d[1] = dir_cnt[1] + dir_cnt[2];
        d[2] = dir_cnt[2] + dir_cnt[3];
        d[3] = dir_cnt[3] + dir_cnt[0];
        int mx_d = max_element(d.begin(), d.end()) - d.begin();
        if(mx_d == 0) change3(x,y,0,1);
        if(mx_d == 1) change3(x,y,1,2);
        if(mx_d == 2) change3(x,y,2,3);
        if(mx_d == 3) change3(x,y,3,0);
    }
    if(num == 4){
        int mn = min_element(dir_cnt.begin(), dir_cnt.end()) - dir_cnt.begin();
        if(mn == 0) change4(x,y,1,2,3);
        if(mn == 1) change4(x,y,2,3,0);
        if(mn == 2) change4(x,y,3,0,1);
        if(mn == 3) change4(x,y,0,1,2);
    }
    if(num == 5){
        change5(x, y);
    }
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
        }
    }
    c_maps = maps;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maps[i][j] >= 1 && maps[i][j] <=5){
                f1(i, j, maps[i][j]);
            }
        }
    }

    int zero_cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << c_maps[i][j];
            if(c_maps[i][j] == 0){
                zero_cnt ++;
            }
        }
        cout << "\n";
    }
    cout << zero_cnt;
}