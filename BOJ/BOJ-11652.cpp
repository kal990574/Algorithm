#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> m;
int main(){
    int N;
    cin >> N;
    ll tmp =0;
    ll mx =0;
    for(int i=0; i<N;i ++){
        cin >> tmp;
        m[tmp]++;
        mx = max(mx, m[tmp]);
    }
    for(auto i : m){
        if(mx == i.second) {
            cout << i.first;
            return 0;
    }
}
}