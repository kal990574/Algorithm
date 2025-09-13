#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    vector<pair<int, int>> diff(N-1);
    vector<int> ban(1, -1);
    int res = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    if(N == 1){
        cout << v[0];
        return 0;
    }

    sort(v.begin(), v.end(), greater<>());

    for(int i=0; i<N-1; i++){
        diff[i].first = (v[i] * v[i+1]) - (v[i] + v[i+1]);
        diff[i].second = i;
    }
    sort(diff.begin(), diff.end(), greater<>());

    for(int i=0; i<N-1; i++){
        if(diff[i].first > 0 && find(ban.begin(), ban.end(), diff[i].second) == ban.end() && find(ban.begin(), ban.end(), diff[i].second + 1) == ban.end()){
            res += (v[diff[i].second] * v[diff[i].second + 1]);
            ban.push_back(diff[i].second);
            ban.push_back(diff[i].second + 1);
        }
    }

    for(int i=0; i<N; i++){
        if(find(ban.begin(), ban.end(), i) == ban.end()){
            res += v[i];
        }
    }
    cout << res << "\n";
}