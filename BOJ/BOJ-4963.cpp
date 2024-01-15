#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > visited(51, vector<int>(51));
vector<vector<int> > maps(51, vector<int>(51));
queue<pair<int, int> > q;
int dx[8] = {-1,1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};
int w,h;
int res;
void bfs(){
    while(!q.empty()){
        int start_X = q.front().first;
        int start_Y = q.front().second;
        q.pop();
        visited[start_X][start_Y] = 1;
        for(int i=0; i<8; i++){
            int next_X = start_X + dx[i];
            int next_Y = start_Y + dy[i];
            if(next_X >=0 && next_X < h && next_Y >=0 && next_Y < w && maps[next_X][next_Y] == 1 && !visited[next_X][next_Y]){
                q.push(make_pair(next_X, next_Y));
                visited[next_X][next_Y] = 1;
                //cout << next_X << next_Y << "\n";
            }
        }
    }
}
int main(){
    while(1){
        cin >> w >> h;
        res = 0;
        if(w == 0 && h == 0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> maps[i][j];
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(maps[i][j] == 1 && !visited[i][j]) {
                    q.push(make_pair(i,j));
                    bfs();
                    res++;
                }
            }
        }   
    cout << res << "\n";
    maps.assign(51, vector<int>(51, 0));
    visited.assign(51, vector<int>(51, 0));
    }
}