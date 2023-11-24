#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > tree(51);
vector<int> visited(51);
int del;
int cnt;

void dfs(int start){
    visited[start] = 1;
    for(int i=0; i<tree[start].size(); i++){
        int next = tree[start][i];
        if(next == del) {
            tree[start].erase(tree[start].begin()+i);
            i=-1;
        }
        if(next != del && !visited[next]){
            dfs(next);
        }
    }
    if(tree[start].empty()) cnt++;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int root = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == -1) {
            root = i;
            continue;
        }
        tree[tmp].push_back(i);
    }
    cin >> del;

    dfs(root);

    if(del == root) cnt = 0;

    cout << cnt;
}