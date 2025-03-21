#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    priority_queue<pair<int, int> > pq; 

    for (int i = 0; i < n; ++i) {
        int front = items[i].first;
        int back = items[i].second;

        pq.push(make_pair(front, 1)); 
        pq.push(make_pair(front + back, 2)); 
    }

    int sum = 0, count = 0;

    while (!pq.empty() && count < m) {
        int value = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (count + cost <= m) {
            sum += value;
            count += cost;
        }
    }

    cout << sum << '\n';
    return 0;
}
