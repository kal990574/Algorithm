#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s_from(m);
    vector<int> s_to(m);
    for(int i=0; i<m; i++){
        cin >> s_from[i];
    }
    for(int i=0; i<m; i++){
        cin >> s_to[i];
    }
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    vector<int> inCycle(n, 1);
    for(int i=0; i<m; i++){
        adj[s_from[i]].push_back(s_to[i]);
        adj[s_to[i]].push_back(s_from[i]);
        degree[s_from[i]]++;
        degree[s_to[i]]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(degree[i] == 1) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inCycle[cur] = 0;
        for(int nxt : adj[cur]){
            degree[nxt]--;
            if(degree[nxt] == 1) q.push(nxt);
        }
    }

    queue<int> q2;
    vector<int> dist(n, -1);
    for(int i=0; i<n; i++){
        if(inCycle[i] == 1){
            q2.push(i);
            dist[i] = 0;
        }
    }
    while(!q2.empty()){
        int cur = q2.front();
        q2.pop();
        for(int nxt : adj[cur]){
            if(dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                q2.push(nxt);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dist[i] << " ";
    }
}