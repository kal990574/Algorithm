#include <bits/stdc++.h>
using namespace std;
int N, L, R;
int maps[51][51];
int visited[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int rmx = 0;
queue<pair<int,int> > uni;

int chk(int sx, int sy, int nx, int ny){
    if(L <= abs(maps[sx][sy] - maps[nx][ny]) && abs(maps[sx][sy] - maps[nx][ny]) <= R){
        return 1;
    }
    else return 0;
}

void bfs(int x, int y){
    queue<pair<int, int> > q;
        //cout << x << y << "\n";
        q.push(make_pair(x,y));
        uni.push(make_pair(x,y));
        visited[x][y] = 1;
        while(!q.empty()){
            int sx = q.front().first;
            int sy = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = sx + dx[i];
                int ny = sy + dy[i];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && chk(sx,sy,nx,ny)){
                    //cout << nx << ny << "\n";
                    q.push(make_pair(nx,ny));
                    uni.push(make_pair(nx,ny));
                    visited[nx][ny] = 1;
                }
            }
    }
}

void move(){
    int cnt = 0;
    int tmp = 0;
    vector<pair<int, int> > v;
    //cout << uni.size() << "\n";
    if(uni.size()>1){
        while(!uni.empty()){
        int x = uni.front().first;
        int y = uni.front().second;
        //cout << x << y << "\n";
        uni.pop();
        tmp += maps[x][y];
        v.push_back(make_pair(x,y));
        cnt ++;
        rmx ++;
        //cout << ch << "\n";
    }
    for(int i=0; i<v.size(); i++){
        maps[v[i].first][v[i].second] = tmp/cnt;
        //cout << tmp/cnt << "\n";
    }
    }
}

void clear(queue<pair<int, int> > &q){
    queue<pair<int,int> > empty;
    swap(q, empty);
}

int main(){
    int res = 0;
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> maps[i][j];
        }
    }
    while(1){
        rmx = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    bfs(i,j);
                    move();
                    clear(uni);
                }
            }
        }
        if(!rmx) break;
        res ++;
    }
    cout << res;
}