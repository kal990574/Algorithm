#include <bits/stdc++.h>
using namespace std;
int N, M;
int cnt;
int arr[1001][1001];
int visited[1001];
queue<int> q;

void bfs(int start){
    q.push(start);
    visited[start] = true;
    cnt++;
    while(!q.empty()){
        start = q.front();
        q.pop();

        for(int i=1; i<=N; i++){
            if(arr[start][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int u,v =0;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for(int i=1; i<=N;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    cout << cnt;
}