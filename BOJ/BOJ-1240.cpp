#include <bits/stdc++.h>
using namespace std;
int tree[1001][1001];
int N, M;

int bfs(int s, int e, vector<int>& visited){
    queue<pair<int, int> > q;
    q.push(make_pair(s, 0));
    visited[s] = 1;
    while(!q.empty()){
        int next = q.front().first;
        int len = q.front().second;
        q.pop();

        for(int i=1; i<=N; i++){
            if(tree[next][i] && !visited[i]){
                int next_len = len + tree[next][i];
                q.push(make_pair(i, next_len));
                visited[i] = 1;
                if(i == e){
                    return next_len;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N-1; i++){
        int node1 = 0;
        int node2 = 0;
        int len = 0;
        cin >> node1 >> node2 >> len;
        tree[node1][node2] = len;
        tree[node2][node1] = len;
    }

    for(int i=0; i<M; i++){
        int node_s = 0;
        int node_e = 0;
        cin >> node_s >> node_e;
        vector<int> visited(N+1);
        int res = bfs(node_s, node_e, visited);
        cout << res << "\n";
    }
}