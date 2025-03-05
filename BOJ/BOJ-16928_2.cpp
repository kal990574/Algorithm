#include <bits/stdc++.h>

using namespace std;

vector<int> maps(101, 0);
int answer = INT_MAX;
unordered_map<int, int> ladders;
unordered_map<int, int> snakes;
vector<int> visited(101, 0);

void bfs(int pos) {
    queue<int> q;
    q.push(pos);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int nx = x + i;
            if(nx <= 100){
                if(maps[nx] == 1 && !visited[ladders[nx]]){
                    visited[ladders[nx]] = visited[x] + 1;
                    q.push(ladders[nx]);
                }
                if(maps[nx] == 2 && !visited[snakes[nx]]){
                    visited[snakes[nx]] = visited[x] + 1;
                    q.push(snakes[nx]);
                }
                if(maps[nx] == 0 && !visited[nx]){
                    visited[nx] = visited[x] + 1;
                    q.push(nx);
                    //cout << nx << "\n";
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladders[x] = y;
        maps[x] = 1;
    }
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        snakes[x] = y;
        maps[x] = 2;
    }
    
    bfs(1);
    cout << visited[100] << '\n';
    
    return 0;
}
