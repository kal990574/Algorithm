#include <bits/stdc++.h>
using namespace std;
int maps[101];
int dice[6] = {1,2,3,4,5,6};
int N, M;
int main(){
    vector<pair<int, int> > ladders;
    vector<pair<int, int> > snakes;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int l1, l2;
        cin >> l1 >> l2;
        ladders.push_back(make_pair(l1, l2));
    }
    for(int i=0; i<M; i++){
        int s1, s2;
        cin >> s1 >> s2;
        snakes.push_back(make_pair(s1, s2));
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int start = q.front();
        q.pop();

        for(int i=0; i<6; i++){
            int next = start + dice[i];
            if(next <= 100){
                for(int i=0; i<N; i++){
                    if(next == ladders[i].first) next = ladders[i].second;
                }
                for(int i=0; i<M; i++){
                    if(next == snakes[i].first) next = snakes[i].second;
                }
                if(!maps[next]){
                    maps[next] = maps[start] + 1;
                    q.push(next);
                }
                
            }
        }
    }
    cout << maps[100];
}