#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(11);
    vector<int> freq(11);
    int res = 0;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        if(freq[a] == 0){
            freq[a]++;
            v[a] = b;
            continue;
        }
        if(v[a] != b){
            res++;
            v[a] = b;
        }
    }
    cout << res;
}