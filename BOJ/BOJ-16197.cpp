#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<char> > maps(20, vector<char>(20));
vector<pair<int, int> > coin;
int visited[20][20][20][20];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int res = 10000;

void bfs(){
    queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q;
    q.push(make_pair(make_pair(make_pair(coin[0].first, coin[0].second), make_pair(coin[1].first, coin[1].second)), 0));

    while(!q.empty()){
        int sx1 = q.front().first.first.first;
        int sy1 = q.front().first.first.second;
        int sx2 = q.front().first.second.first; 
        int sy2 = q.front().first.second.second;
        int dist = q.front().second;
        q.pop();
        visited[sx1][sy1][sx2][sy2] = 1;

        for(int i=0; i<4; i++){
            int nx1 = sx1 + dx[i];
            int ny1 = sy1 + dy[i];
            int nx2 = sx2 + dx[i];
            int ny2 = sy2 + dy[i];

            //cout << nx1 << " " << ny1 << " " << nx2 << " " << ny2 << "\n"; 

            if((nx1<0||nx1>=N||ny1<0||ny1>=M) && (nx2<0||nx2>=N||ny2<0||ny2>=M)) continue;

            if(nx1<0||nx2<0||ny1<0||ny2<0||nx1>=N||nx2>=N||ny1>=M||ny2>=M){
                res = min(res, dist + 1);
                //cout << "res: " << res;
                break;
            }

            if((maps[nx1][ny1] == '.' || maps[nx1][ny1] == 'o') && (maps[nx2][ny2] == '.' || maps[nx2][ny2] == 'o') && !visited[nx1][ny1][nx2][ny2] && !visited[nx1][ny1][nx2][ny2]){
                q.push(make_pair(make_pair(make_pair(nx1, ny1), make_pair(nx2, ny2)), dist+1));
                visited[nx1][ny1][nx2][ny2] = 1;
            }

            if(maps[nx1][ny1] == '#' && maps[nx2][ny2] != '#' && !visited[sx1][sy1][nx2][ny2]){
                q.push(make_pair(make_pair(make_pair(sx1, sy1), make_pair(nx2, ny2)), dist+1));
                visited[sx1][sy1][nx2][ny2] = 1;
            }

            if(maps[nx2][ny2] == '#' && maps[nx1][ny1] != '#' && !visited[nx1][ny1][sx2][sy2]){
                q.push(make_pair(make_pair(make_pair(nx1, ny1), make_pair(sx2, sy2)), dist+1));
                visited[nx1][ny1][sx2][sy2] = 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'o') coin.push_back(make_pair(i,j));
        }
    }
    bfs();
    if(res > 10) res = -1;
    cout << res << "\n";
}