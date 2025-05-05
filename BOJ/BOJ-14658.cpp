#include <bits/stdc++.h>
using namespace std;
int N, M, L, K;
vector<pair<int, int> > stars;
int main(){
    cin >> N >> M >> L >> K;
    for(int i=0; i<K; i++){
        int x,y;
        cin >> x >> y;
        stars.push_back(make_pair(x,y));
    }
    int res = 0;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            int cnt = 0;
            int sx = stars[i].first;
            int sy = stars[j].second;
            for(int k=0; k<K; k++){
                if(sx <= stars[k].first && sy <= stars[k].second && sx+L >= stars[k].first && sy+L >= stars[k].second){
                    cnt++;
            }
        }
        res = max(res, cnt);
        }
    }
    cout << K - res << "\n";
}