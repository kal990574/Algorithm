#include <bits/stdc++.h>
using namespace std;
set<string> visited[11];
int res = 0;
void dfs(string number, int depth, int k){
    if(depth == k){
        res = max(res, stoi(number));
        return;
    }

    if(visited[depth].count(number)) return;
    visited[depth].insert(number);
    for(int i=0; i<number.length()-1; i++){
        for(int j=i+1; j<number.length(); j++){
            swap(number[i], number[j]);
            dfs(number, depth+1, k);
            swap(number[i], number[j]);
        }
    }
}
int main(){
    string num;
    int chance;
    cin >> num >> chance;
    for(int i=1; i<11; i++){
        visited[i].clear();
    }
    dfs(num, 0, chance);
    cout << res;
}