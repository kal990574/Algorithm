#include <bits/stdc++.h>
using namespace std;
// 브루트포스, 백트래킹으로 전체 중에 최적의 방법을 택해야됨
// 함수 통합
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int> > maps(8, vector<int>(8));
vector<vector<int> > copy_maps(8, vector<int>(8));
vector<pair<int,int> > cameras;
vector<vector<vector<int> > > directions(6);
int zero_cnt = 65;

void init_directions() {
    vector<int> temp;

    temp.push_back(0); directions[1].push_back(temp); temp.clear();
    temp.push_back(1); directions[1].push_back(temp); temp.clear();
    temp.push_back(2); directions[1].push_back(temp); temp.clear();
    temp.push_back(3); directions[1].push_back(temp); temp.clear();

    temp.push_back(0); temp.push_back(2); directions[2].push_back(temp); temp.clear();
    temp.push_back(1); temp.push_back(3); directions[2].push_back(temp); temp.clear();

    temp.push_back(0); temp.push_back(1); directions[3].push_back(temp); temp.clear();
    temp.push_back(1); temp.push_back(2); directions[3].push_back(temp); temp.clear();
    temp.push_back(2); temp.push_back(3); directions[3].push_back(temp); temp.clear();
    temp.push_back(3); temp.push_back(0); directions[3].push_back(temp); temp.clear();

    temp.push_back(0); temp.push_back(1); temp.push_back(2); directions[4].push_back(temp); temp.clear();
    temp.push_back(1); temp.push_back(2); temp.push_back(3); directions[4].push_back(temp); temp.clear();
    temp.push_back(2); temp.push_back(3); temp.push_back(0); directions[4].push_back(temp); temp.clear();
    temp.push_back(3); temp.push_back(0); temp.push_back(1); directions[4].push_back(temp); temp.clear();

    temp.push_back(0); temp.push_back(1); temp.push_back(2); temp.push_back(3); directions[5].push_back(temp); temp.clear();
}

void change(int x, int y, vector<int> dirs, vector<vector<int> >& m){
    for (int dir : dirs) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[dir];
            ny += dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || m[nx][ny] == 6) break;
            if (m[nx][ny] == 0) m[nx][ny] = -1;
        }
    }
}

int countZero(vector<vector<int> > m) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (m[i][j] == 0) cnt++;
    return cnt;
}

void dfs(int idx, vector<vector<int> >& m){
    if(idx == cameras.size()){
        zero_cnt = min(zero_cnt, countZero(m));
        return;
    }
    int x = cameras[idx].first;
    int y = cameras[idx].second;
    int type = m[x][y];
    for(auto dir : directions[type]){
        vector<vector<int> > backup = m;
        change(x, y, dir, m);
        dfs(idx + 1, m);
        m = backup;
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maps[i][j];
            if(maps[i][j]>=1 && maps[i][j] <=5){
                cameras.push_back(make_pair(i,j));
            }
        }
    }
    init_directions();
    dfs(0, maps);
    cout << zero_cnt << "\n";
}