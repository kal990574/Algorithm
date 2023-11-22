#include <bits/stdc++.h>
using namespace std;
int M,N;
int maps[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int> > q;
int visited[1001][1001];
int res;

void bfs(){
    while(!q.empty()){
        
        int start_x = q.front().first;
        int start_y = q.front().second;
        for(int i=0; i<4; i++){
            int next_x = start_x + dx[i];
            int next_y = start_y + dy[i];
            
            if(next_x >= 0 && next_x < M && next_y >=0 && next_y < N && maps[next_x][next_y] == 0 && !visited[next_x][next_y]){
                q.push(make_pair(next_x, next_y));
                maps[next_x][next_y] = 1;
                visited[next_x][next_y] = visited[start_x][start_y] + 1; 
                res = visited[next_x][next_y];
            }
        }
    }
}

int main(){
    // m by n
    cin >> N >> M;
    for(int i=0; i<M; i++){
        for(int j=0; j < N; j++){
            cin >> maps[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(maps[i][j] == 1) q.push(make_pair(i,j));
        }
    }

    bfs();

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(maps[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }   
    }
    cout << res;
}