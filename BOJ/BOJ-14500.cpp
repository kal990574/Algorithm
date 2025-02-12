#include <bits/stdc++.h>
using namespace std;
int N, M;
int maps[501][501];
int res = 0;
int dx[3] = {0, -1, 1};
int dy[3] = {1, 0, 0};
int visited[501][501];

void bruteforce(int x, int y){
    if (x >= 1 && y >= 1 && y + 1 < M) // ㅗ
        res = max(res, maps[x][y] + maps[x-1][y] + maps[x][y-1] + maps[x][y+1]);
    if (x + 1 < N && y >= 1 && y + 1 < M) // ㅜ
        res = max(res, maps[x][y] + maps[x+1][y] + maps[x][y-1] + maps[x][y+1]);
    if (x >= 1 && x + 1 < N && y + 1 < M) // ㅏ
        res = max(res, maps[x][y] + maps[x-1][y] + maps[x+1][y] + maps[x][y+1]);
    if (x >= 1 && x + 1 < N && y >= 1) // ㅓ
        res = max(res, maps[x][y] + maps[x-1][y] + maps[x+1][y] + maps[x][y-1]);
}

void dfs(int x, int y, int cnt, int sum){
    sum += maps[x][y];
    if(cnt == 4){
        res = max(res, sum);
        return;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >=0 && ny < M && !visited[nx][ny]){
                visited[nx][ny] = 1;
                dfs(nx, ny, cnt + 1, sum);
                visited[nx][ny] = 0;
            }
        }
    }
}

int main(){
    //테테테테트로미노
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> maps[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            bruteforce(i,j);
            visited[i][j] = 1;
            dfs(i, j, 1, 0);
            visited[i][j] = 0;
        }
    }
    cout << res << "\n";
}