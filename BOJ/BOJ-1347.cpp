#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > maps(100, vector<char>(100, '#'));
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    vector<pair<int, int> > dir;
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,1));

    for(int i=0; i<n; i++){
        v.push_back(s[i]);
    }

    int dir_cnt = 0;
    int curX = 49;
    int curY = 49;
    int minX = 49, minY = 49, maxX = 49, maxY = 49;
    maps[curX][curY] = '.';
    for(int i=0; i<v.size(); i++){
        if(v[i] == 'R'){
            if(dir_cnt == 3) dir_cnt = 0;
            else dir_cnt ++;
        }
        if(v[i] == 'L'){
            if(dir_cnt == 0) dir_cnt = 3;
            else dir_cnt --;
        }

        if(v[i] == 'F'){
            int dx = dir[dir_cnt].first;
            int dy = dir[dir_cnt].second;
            curX += dx;
            curY += dy;
            minX = min(minX, curX);
            maxX = max(maxX, curX);
            minY = min(minY, curY);
            maxY = max(maxY, curY);
            maps[curX][curY] = '.';
        }
    }
    for(int i=minX; i<=maxX; i++){
        for(int j=minY; j<=maxY; j++){
            cout << maps[i][j];
        }
        cout << "\n";
    }
}