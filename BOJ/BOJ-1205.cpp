#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, P, new_score;
    cin >> N >> new_score >> P;
    vector<int> scores(N);
    int dup = 0;
    int ans = 1;
    int ans2 = 0;
    for(int i=0; i<N; i++){
        cin >> scores[i];
    }
    for(int i=0; i<scores.size(); i++){
        if(scores[i] > new_score){
            ans++;
        }
        if(scores[i] == new_score){
            ans2++;
        }
    }
    if(ans+ans2 == P+1) ans = -1;
    cout << ans;
}