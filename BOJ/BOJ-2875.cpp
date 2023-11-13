#include <bits/stdc++.h>
using namespace std;
int N,M,K;

int main(){
    cin >> N >> M >> K;
    while(K>0){
        if(N>2*M){
            N -= 1;
        }
        else {
            M -= 1;
        }
        K--;
    }
    if(N==0||M==0) cout << 0;
    else if(N>2*M) cout << M;
    else cout << N/2;
}