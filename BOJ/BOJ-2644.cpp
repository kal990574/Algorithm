#include <bits/stdc++.h>
using namespace std;
int n;
int a,b;
int m;
int u,v;
int graph[101][101];
int visited[101];
queue<int> q;
int cnt[101];
int res;

void bfs(int start){
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        start = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[start][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
                cnt[i] = cnt[start] + 1;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    bfs(a);
    if(cnt[b] == 0) cout << -1;
    else cout << cnt[b];
}