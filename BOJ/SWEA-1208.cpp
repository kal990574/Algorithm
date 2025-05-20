#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(100);
    for(int i=0; i<100; i++){
        cin >> v[i];
    }
    while(N--){
        int mx_idx = max_element(v.begin(), v.end()) - v.begin();
        int mn_idx = min_element(v.begin(), v.end()) - v.begin();
        if(v[mx_idx] > v[mn_idx]){
            v[mx_idx] -= 1;
            v[mn_idx] += 1;
        }
        int mx = *max_element(v.begin(), v.end());
        int mn = *min_element(v.begin(), v.end());
        if(mx - mn == 0 || mx - mn == 1) break; 
    }
    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}