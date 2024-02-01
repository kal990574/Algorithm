#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l;
    cin >> n >> l;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    for(int i=0; i<h.size(); i++){
        if(l >= h[i]){
            l += 1;
        }
    }
    cout << l;
}