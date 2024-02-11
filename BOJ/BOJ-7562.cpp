#include <bits/stdc++.h>
using namespace std;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int res = 0;
queue<pair<int,int> > q;
int I;
vector<vector<int> > visited(301, vector<int>(301));
vector<vector<int> > maps(I, vector<int>(I));

void bfs(int sx, int sy, int fx, int fy){
    q.push(make_pair(sx,sy));
    visited[sx][sy] = 1;
    while(!q.empty()){
        int start_x = q.front().first;
        int start_y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int next_x = start_x + dx[i];
            int next_y = start_y + dy[i];
            if(next_x >=0 && next_x < I && next_y >=0 && next_y < I && !visited[next_x][next_y]){
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = visited[start_x][start_y] + 1;
                if(next_x == fx && next_y == fy) break;
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    while(T){
        cin >> I;
        maps.assign(I, vector<int>(I,0));
        visited.assign(301, vector<int>(301,0));
        int sx,sy;
        int fx,fy;
        cin >> sx >> sy;
        cin >> fx >> fy;
        bfs(sx,sy,fx,fy);
        T--;
        cout << visited[fx][fy] - 1 << "\n";
    }
}