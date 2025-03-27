#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<char> > maps(20, vector<char>(20));
vector<pair<int, int> > coin;
bool visited[20][20][20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int res = 100000;

void dfs(int x1, int y1, int x2, int y2, int depth) {
    if (depth > 10) return;

    if ((x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) && (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M)) return;

    if(x1<0||x2<0||y1<0||y2<0||x1>=N||x2>=N||y1>=M||y2>=M){
        res = min(res, depth);
        //cout << "res: " << res;
        return;
    }

    if (visited[x1][y1][x2][y2]) return;

    visited[x1][y1][x2][y2] = true;

    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        if (nx1 >= 0 && nx1 < N && ny1 >= 0 && ny1 < M && maps[nx1][ny1] == '#') {
            nx1 = x1;
            ny1 = y1;
        }
        if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M && maps[nx2][ny2] == '#') {
            nx2 = x2;
            ny2 = y2;
        }

        dfs(nx1, ny1, nx2, ny2, depth + 1);
    }

    visited[x1][y1][x2][y2] = false; 
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'o') {
                coin.push_back(make_pair(i,j));
            }
        }
    }

    dfs(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0);

    if (res > 10) res = -1;
    cout << res << "\n";
}
