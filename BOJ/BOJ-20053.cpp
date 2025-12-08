#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        vector<int> v(N);
        int mn = INT_MAX;
        int mx = INT_MIN;

        for(int i=0; i<N; i++){
            cin >> v[i];
            if(mn > v[i]) mn = v[i];
            if(mx < v[i]) mx = v[i];
        }
        cout << mn << " " << mx << "\n";   
    }
}