#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<vector<int> > v;
vector<vector<int> > visited;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> mx;
int one_num = 0;
int cnt = 0;

void dfs(int startX, int startY){
    visited[startX][startY] = 1;
    one_num++;
    for(int i=0; i<4; i++){
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];
        if(nextX >=0 && nextY >= 0 && nextX < M && nextY < N && v[nextX][nextY] == 1 && !visited[nextX][nextY]){
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY);
        }
    }
    mx.push_back(one_num);
}
int main(){
    cin >> M >> N;
    v = vector<vector<int> >(M, vector<int>(N));
    visited = vector<vector<int> >(M, vector<int>(N));

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(v[i][j] == 1 && !visited[i][j]){
                cnt ++;
                one_num = 0;
                dfs(i,j);
            }
        }
    }
    cout << cnt << "\n";
    if(cnt == 0) cout << 0;
    else cout << *max_element(mx.begin(), mx.end());

}