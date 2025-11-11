#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        for(int i=a-1; i<=b-1; i++){
            v[i] = c;
        }
    }
    for(int i=0; i<N; i++){
        cout << v[i] << " ";
    }
}