#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAX = 2000000;
    vector<int> maps(MAX + 1, -1);
    
    int N, K;
    cin >> N >> K;

    if(N >= K){
        cout << N - K;
        return 0;
    }

    queue<int> q;
    q.push(N);
    maps[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            cout << maps[cur];
            return 0;
        }

        vector<int> next_positions;
        next_positions.push_back(cur * 2);
        next_positions.push_back(cur - 1);
        next_positions.push_back(cur + 1);
        for (int next : next_positions) {
            if (next >= 0 && next <= MAX && maps[next] == -1) {
                if (next == cur * 2) {
                    maps[next] = maps[cur];
                } else {
                    maps[next] = maps[cur] + 1;
                }
                q.push(next);
            }
        }
    }
    return 0;
}
