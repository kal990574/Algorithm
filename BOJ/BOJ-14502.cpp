#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<vector<int> > visited(8, vector<int>(8));
vector<vector<int> > maps(8,vector<int>(8));
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cnt = 0;
int mx_cnt = 0;

void dfs(int startX, int startY){
    visited[startX][startY] = 1;
    for(int i=0; i<4; i++){
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];
        if(nextX >=0 && nextX < N && nextY >=0 && nextY < M && maps[nextX][nextY] == 0 && !visited[nextX][nextY]){
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY);
            
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
        }
    }
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(cnt == 3) {
                    dfs(i,j);
                }
                if(maps[i][j] == 0) {
                    maps[i][j] = 1;
                    cnt ++;
                }
            }
    }
    
}