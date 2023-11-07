#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<long long> v;
    int K,N;
    cin >> K >> N;
    int tmp;
    int cnt = 0;
    long long mid = 0;
    int res = 0;
    for(int i=0; i<K; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    long long low = 1;
    long long high = *max_element(v.begin(), v.end());
    while(low <= high){
        mid = (low + high) / 2;
        for(int i=0; i<v.size(); i++){
            cnt += (v[i] / mid);
        }
        if(cnt < N) high = mid -1;
        if(cnt >= N) {
            res = mid;
            low = mid +1;
        }
        cnt = 0;
    }
    cout << res;
}