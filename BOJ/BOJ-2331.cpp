#include <bits/stdc++.h>
using namespace std;

int A, P;
vector<int> visited(300001);

void dfs(int start){
    visited[start]++;
    if(visited[start] == 3)
        return ;
    int sum = 0;
    while(start){
        sum += (int)pow((start%10),P);
        start /= 10;
    }
    dfs(sum);
}
int main(){
    cin >> A >> P;
    dfs(A);
    int res = 0;
    for(int i=0; i< 300001; i++){
        if(visited[i] == 1)
        res ++;
    }
    cout << res;
}