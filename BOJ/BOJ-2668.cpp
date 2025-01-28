#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> cycle;
vector<int> v(N+1);
vector<int> visited(N+1);
vector<int> same;
int in_cycle = 0;

void dfs(int top, int start){
    visited[top] = 1;
    int bottom = v[top];
    cycle.push_back(top);
    if(bottom == start){
        in_cycle = 1;
        return ;
    }
    if(!visited[bottom]){
        dfs(bottom, start);
    }
}

int main(){
    cin >> N;
    for(int i=1; i<N+1; i++){
        cin >> v[i];
        if(i == v[i]) same.push_back(i);
    }

    for(int i=1; i<N+1; i++){
        if(!visited[i]){
            dfs(i, i);
            if(!in_cycle){

            }
        }
    }

}