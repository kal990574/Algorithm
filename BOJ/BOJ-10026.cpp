#include <bits/stdc++.h>
using namespace std;
int N;
char maps[101][101];
int visited[101][101];
int c_res;
int rg_res;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void c_dfs(int x, int y, char color){
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny] && maps[nx][ny] == color && nx >= 0 && nx < N && ny >= 0 && ny < N){
            c_dfs(nx,ny,maps[nx][ny]);
        }
    }
}

void rg_dfs(int x, int y, char color){
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny] && nx >= 0 && nx < N && ny >= 0 && ny < N){
            if(maps[nx][ny] == 'R' || maps[nx][ny] == 'G') {
                rg_dfs(nx,ny,maps[nx][ny]);
        }
    }
}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> maps[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                c_dfs(i,j, maps[i][j]);
                c_res += 1;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                if(maps[i][j] == 'B') c_dfs(i,j,maps[i][j]);
                else rg_dfs(i,j,maps[i][j]);
                rg_res += 1;
            }
        }
    }
    cout << c_res << " " << rg_res;
}