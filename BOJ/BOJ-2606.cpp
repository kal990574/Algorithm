#include <iostream>
#include <memory.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int n,m;
vector<vector<int>> v(101, vector<int>(101));
vector<int> visited(101);
int cnt = 0;
void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int sx = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(v[sx][i] != 0 && !visited[i]){
                visited[i] = 1;
                q.push(i);
                cnt ++;
            }
        }
    }
}
int main(){
    //17:33
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    visited[1] = 1;
    bfs(1);
    cout << cnt;
}