#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v(101);
int visited[101];
vector<int> cycle;
int in_cycle = 0;

void dfs(int top, int start){
    if(visited[top]){
        if(top == start) cycle.push_back(top);
        return;
    }
    visited[top] = 1;
    dfs(v[top], start);
}

int main(){
    cin >> N;

    for(int i=1; i<N+1; i++){
        cin >> v[i];
    }

    for(int i=1; i<N+1; i++){
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    cout << cycle.size() << "\n";
    for(int i=0; i<cycle.size(); i++){
        cout << cycle[i] << "\n";
    }
    
}