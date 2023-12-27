#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int k=0; k<i; k++){
            cout << " ";
        }
        for(int j=0; j<2*N-1-2*i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i=1; i<N; i++){
        for(int k=0; k<N-i-1; k++){
            cout << " ";
        }
        for(int j=0; j<2*i+1; j++){
            cout << "*";
        }
        cout << "\n";
    }
}