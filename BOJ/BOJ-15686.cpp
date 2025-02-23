#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > maps(51, vector<int>((51)));
vector<pair<int, int> > chik;
vector<pair<int, int> > home;
int ans = INT_MAX;
/*
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2
*/
//조합의 경우의수 구한 후
//절대값 거리 계산
//그 중 최소 값 도출
//방식은 재귀, 백트래킹 활용
void dfs(int idx, vector<pair<int, int> >& perm){
    if(perm.size() == M){
        int sum = 0;
        for(int i=0; i<home.size(); i++){
            int min_dist = INT_MAX;
            for(int j=0; j<perm.size(); j++){
                int tmp = abs(home[i].first - perm[j].first) + abs(home[i].second - perm[j].second);
                min_dist = min(min_dist, tmp);
            }
            sum += min_dist;
        }
        ans = min(sum, ans);
        return ;
    }

    for(int i=idx; i<chik.size(); i++){
        perm.push_back(make_pair(chik[i].first, chik[i].second));
        dfs(i+1, perm);
        perm.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 1){
                home.push_back(make_pair(i, j));
            }
            if(maps[i][j] == 2){
                chik.push_back(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int> > per;
    dfs(0, per);
    cout << ans;
}