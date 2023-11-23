#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<vector<int> > tree(MAX);
vector<int> parent(MAX);
vector<int> visited(MAX);

void dfs(int start){
    visited[start] = 1;
    for(int i=0; i < tree[start].size(); i++){
        int next = tree[start][i];
        if(!visited[next]){
            parent[next] = start;
            dfs(next);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    dfs(1);
    for(int i=2; i <= n; i++){
        cout << parent[i] << "\n";
    }
}