#include <bits/stdc++.h>
using namespace std;
int N, Q;
vector<vector<pair<int, int> > > graph;
int res = 0;
void dfs(int k, int cur, int usado, vector<int>& visited){
    for(auto& next : graph[cur]){
        int next_node = next.first;
        int next_usado = next.second;
        if(visited[next_node]) continue;
        
        visited[next_node] = 1;
        int mins = min(usado, next_usado);
        if(mins >= k) res++;
        dfs(k, next_node, mins, visited);
    }
}

int main(){
    cin >> N >> Q;
    graph.resize(N+1);
    for(int i=0; i<N-1; i++){
        int cost, to, from;
        cin >> to >> from >> cost;
        graph[to].emplace_back(make_pair(from, cost));
        graph[from].emplace_back(make_pair(to,cost));
    }
    for(int i=0; i<Q; i++){
        int k, v;
        cin >> k >> v;

        vector<int> visited(N+1);
        visited[v] = 1;
        res = 0;

        dfs(k, v, INT_MAX, visited);

        cout << res << "\n";
    }
}