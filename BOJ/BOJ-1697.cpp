#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int N, K;
vector<int> cnt(100001); 
vector<int> visited(100001);

void bfs(int start){
    dq.push_back(start);
    visited[start] = 1;

    while(!dq.empty()){
        int next = dq.front();
        if(next == K) break;
        dq.pop_front();
        if(next + 1 >= 0 && next + 1 < 100001 && !visited[next + 1]){
            cnt[next + 1] = cnt[next] + 1;
            visited[next+1] = 1;
            dq.push_back(next + 1);
        }
        if(next - 1 >= 0 && next - 1 < 100001 && !visited[next - 1]){
            cnt[next - 1] = cnt[next] + 1;
            visited[next-1]=1;
            dq.push_back(next - 1);
        }
        if(2*next >= 0 && 2 * next < 100001 && !visited[2*next]){
            visited[2*next] = 1;
            cnt[2 * next] = cnt[next] + 1;
            dq.push_back(2*next);
        }
    }
}

int main(){
    cin >> N >> K;
    bfs(N);
    cout << cnt[K];
}