#include <bits/stdc++.h>
using namespace std;
int N;
int maps[126][126];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dijkstra(){
    vector<vector<int> > dist(N, vector<int>(N, INT_MAX));
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

    dist[0][0] = maps[0][0];
    pq.push(make_pair(maps[0][0], make_pair(0,0)));

    while(!pq.empty()){
        int cur = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        //cout << x << " " << y << "\n";
        if(x == N-1 && y == N-1){
            return dist[x][y];
        }
        
        if(dist[x][y] < cur) continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                int next = cur + maps[nx][ny];
                if(next < dist[nx][ny]){
                    dist[nx][ny] = next;
                    pq.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
}

int main(){
    int num = 1;
    while(cin >> N && N != 0){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> maps[i][j];
            }
        }
        cout << "Problem " << num << ": " << dijkstra() << "\n";
        num ++;
    }
}