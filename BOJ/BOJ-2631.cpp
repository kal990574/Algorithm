#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin >> N;
    vector<int> v(N);
    vector<int> dp(N, 1);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << N - *max_element(dp.begin(), dp.end());
}