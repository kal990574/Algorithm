#include <bits/stdc++.h>
using namespace std;
int main(){
    int X;
    cin >> X;
    int N;
    cin >> N;
    int sum = 0;
    vector<pair<int,int>> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i].first >> v[i].second;
        sum += (v[i].first * v[i].second);
    }
    if(X == sum) cout << "Yes";
    else cout << "No";
}