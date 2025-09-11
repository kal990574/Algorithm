#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];

    unordered_map<string, vector<int>> mp;
    mp.reserve(N * 50); 

    for (int i = 0; i < N; i++) {
        string pref = "";
        for (char c : words[i]) {
            pref.push_back(c);
            auto &vec = mp[pref];
            if (vec.size() < 2) {
                vec.push_back(i);
            }
        }
    }

    int bestLen = -1;
    pair<int,int> best = {1e9, 1e9};

    for (auto &kv : mp) {
        auto &vec = kv.second;
        if (vec.size() < 2) continue;

        int len = kv.first.size();
        int a = vec[0], b = vec[1];
        int S = a, T = b;
        if (S > T) swap(S,T);

        if (len > bestLen) {
            bestLen = len;
            best = {S,T};
        } else if (len == bestLen) {
            if (S < best.first || (S == best.first && T < best.second)) {
                best = {S,T};
            }
        }
    }

    cout << words[best.first] << "\n" << words[best.second] << "\n";
}
