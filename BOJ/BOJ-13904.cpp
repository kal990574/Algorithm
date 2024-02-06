#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int tmp = v[0];
    int idx = 0;
    while(tmp > *max_element(v.begin(), v.end())){
        idx ++;
        v[0] += 1;
    }
}