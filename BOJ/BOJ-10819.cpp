#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int result =0;
    int value = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while(next_permutation(v.begin(), v.end())){
        for(int i=0; i<n-1; i++){
            value += abs(v[i] - v[i+1]);
        }
        result = max(result, value);
        value = 0;
    }
    cout << result;
}