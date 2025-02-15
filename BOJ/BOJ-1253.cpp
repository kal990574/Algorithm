#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int res = 0;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    //cout << v[0];
    sort(v.begin(), v.end());
    //cout << v[0];
    for(int i=0; i<N; i++){
        int start = 0;
        int end = N-1;
        int tmp = v[i];
        //cout << tmp;
        while(start < end){
            if(start == i){
                start ++;
                continue;
            }
            if(end == i){
                end --;
                continue;
            }
            if(tmp == v[start] + v[end]){
                //cout << tmp << "\n";
                res ++;
                break;
            }
            if(tmp < v[start] + v[end]){
                end --;
            }
            if(tmp > v[start] + v[end]){
                start ++;
            }
        }
    }

    cout << res;
}