#include <bits/stdc++.h>
using namespace std;
int M, N;
int visited[8][8];
int maps[8][8];
int copy_maps[8][8];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int res = 0;

bool range(int x, int y){
    if(x>=0 && x<N && y>=0 && y<M) return true;
    else return false;
}

void bfs(){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > q;
    int spread[8][8];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            spread[i][j] = maps[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(spread[i][j]==2 && !visited[i][j]){
                q.push(make_pair(i,j));
                //cout << i <<" "<< j << "\n";
                visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(range(nx,ny) && !visited[nx][ny] && spread[nx][ny] == 0){
                            visited[nx][ny] = 1;
                            spread[nx][ny] = 2;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(spread[i][j] == 0)
                cnt ++;
        }
    }
    res = max(cnt, res);
    //cout << cnt << "\n";
}

void insert_wall(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maps[i][j] == 0){
                maps[i][j] = 1;
                insert_wall(cnt+1);
                maps[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> copy_maps[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(copy_maps[i][j] == 0){
                for(int k=0; k<N; k++){
                    for(int l=0; l<M; l++){
                        maps[k][l] = copy_maps[k][l];
                    }
                }
                maps[i][j] = 1;
                insert_wall(1);
                maps[i][j] = 0;
            }
        }
    }
    cout << res;
}