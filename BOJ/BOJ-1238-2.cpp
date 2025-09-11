#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,X;
    cin >> N >> M >> X;
    vector<vector<pair<int,int>>> graph(N+1);
    vector<vector<pair<int,int>>> revGraph(N+1);
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        revGraph[b].push_back({a,c});
    }
    auto dijkstra = [&](int start, vector<vector<pair<int,int>>> &g){
        vector<int> dist(N+1, 1e9);
        dist[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto [cost, now] = pq.top();
            pq.pop();
            if(dist[now] < cost) continue;
            for(auto &[nxt, c] : g[now]){
                if(dist[nxt] > dist[now] + c){
                    dist[nxt] = dist[now] + c;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return dist;
    };
    auto distFromX = dijkstra(X, graph);
    auto distToX = dijkstra(X, revGraph);
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(i == X) continue;
        ans = max(ans, distToX[i] + distFromX[i]);
    }
    cout << ans << "\n";
}