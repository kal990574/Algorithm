#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int k =N-i; k<N; k++){
            cout << " ";
        }
        for(int j=N-i; j>0; j--){
            cout << "*";
        }
        cout << "\n";
    }
}