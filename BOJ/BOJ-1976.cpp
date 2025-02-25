#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > v;
vector<int> plan;
int ans = 0;
void bfs(int start, int end, vector<int>& visit){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int s = q.front();
        //cout << s << "\n";
        if(s == end){
            ans = 1;
            return ;
        }
        visit[s] = 1;
        q.pop();
        if(v[s].size() == 0){
            return ;
        }
        else{
            for(int i : v[s]){
                if(!visit[i]){
                    q.push(i);
                }
        }
        }
    }
}
int main(){
    cin >> N >> M;
    v.resize(N+1);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1){
                v[i].push_back(j);
                //cout << j << "\n";
            }
        }
    }
    for(int i=0; i<M; i++){
        int t = 0;
        cin >> t;
        plan.push_back(t);
    }
    if(N == 1){
        cout << "YES";
        return 0;
    }
    for(int i=0; i<M-1; i++){
        vector<int> visited(N+1);
        ans = 0;
        bfs(plan[i], plan[i+1], visited);
        if(ans == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}