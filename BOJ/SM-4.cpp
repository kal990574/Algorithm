#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > items(n); 
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
    // 초기값
    dp[0][0] = 0; 

    for (int i = 0; i < n; ++i) {
        int a = items[i].first;
        int b = items[i].second;

        for (int j = 0; j <= m; ++j) {
            if (dp[i][j] == -1) continue;

            // 선택 x
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            // 앞에만
            if (j + 1 <= m)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a);

            // 둘 다
            if (j + 2 <= m)
                dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + a + b);
        }
    }

    int answer = 0;
    for (int j = 0; j <= m; ++j) {
        answer = max(answer, dp[n][j]);
    }

    cout << answer << '\n';
    return 0;
}
