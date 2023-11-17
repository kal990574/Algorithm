#include <bits/stdc++.h>
using namespace std;
int T, N;
int cnt;
queue<int> q;

void bfs(int start, int graph[][1001], int visited[]){
    q.push(start);
    visited[start] = true;
    cnt++;
    
    while(!q.empty()){
        start = q.front();
        q.pop();

        for(int i=1; i<=N;i++){
            if(graph[start][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }  
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>T;
    for(int i=0; i<T; i++){
        int graph[1001][1001] ={0, };
        int visited[1001] = {0, };
        cnt = 0;
        cin >> N;
        for(int j=1; j<=N; j++){
            int u;
            cin >> u;
            graph[j][u] = 1;
        }
        for(int k=1; k<=N; k++){
            if(!visited[k]){
                bfs(k, graph, visited);
            }
        }
        cout << cnt << "\n";
    }
}