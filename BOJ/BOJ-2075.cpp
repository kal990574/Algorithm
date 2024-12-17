#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, tmp;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;

            if (pq.size() < N) { 
                pq.push(tmp);
            } else if (tmp > pq.top()) { 
                pq.pop();
                pq.push(tmp);
            }
        }
    }

    cout << pq.top();
    return 0;
}
