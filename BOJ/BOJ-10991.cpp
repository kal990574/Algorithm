#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        for(int k=0; k<1+2*i; k++){
            if(k%2 == 0) cout << "*";
            if(k%2 == 1) cout << " ";
        }
        cout <<"\n";
    }
}