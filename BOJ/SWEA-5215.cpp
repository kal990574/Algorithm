#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, L;
    cin >> N >> L;
    vector<int> points(N);
    vector<int> calories(N);
    vector<int> dp(L+1, 0);
    for(int i=0; i<N; i++){
        cin >> points[i] >> calories[i];
    }
    for(int i=0; i<N; i++){
        for(int j = L; j>=calories[i]; j--){
            dp[j] = max(dp[j], dp[j-calories[i]] + points[i]);
        }
    }
    
    int result = *max_element(dp.begin(), dp.end());
    cout << "#" << test_case << " " << result << "\n";
}