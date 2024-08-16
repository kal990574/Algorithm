#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int N,M;
vector<pair<int, int> > graph[50001];
int dist[50001];
priority_queue<pair<int, int> > pq;

void dijkstra(int start){
    for (int i = 1; i <= N; i++) dist[i] = INF;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i=0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int newcost = graph[cur][i].second + cost;
            if(dist[next] > newcost) {
                dist[next] = newcost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int start, fin, cow;
        cin >> start >> fin >> cow;
        graph[start].push_back(make_pair(fin, cow));
        graph[fin].push_back(make_pair(start,cow));
    }
    dijkstra(1);
    cout << dist[N];
}