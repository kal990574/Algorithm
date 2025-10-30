#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    for(int i=0; i<N; i++){
        if(v[i] < X){
            cout << v[i] << " ";
        }
    }
}