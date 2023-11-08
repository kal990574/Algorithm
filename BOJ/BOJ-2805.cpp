#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ll N, M;
    cin >> N >> M;
    ll K;
    vector<ll> v;
    for(int i=0; i<N; i++){
        cin >> K;
        v.push_back(K);
    }
    ll low = 1;
    ll high = *max_element(v.begin(), v.end());
    ll res = 0; 
    while(low <= high){
        ll mid = (low+high) / 2;
        ll tmp = 0;
        for(int i=0; i < v.size(); i++){
            if(!(v[i] < mid)){
                tmp += (v[i] - mid);
            }
        }
        if(tmp < M){
            high = mid - 1;
        }
        if(tmp >= M){
            res = mid;
            low = mid + 1;
        }
    }
    cout << res;
}