#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        if(i == n-1){
            for(int m=0; m<2*n-1; m++) cout <<"*";
        }
        else{
            for(int k=0; k<1+2*i; k++){
                if(k == 0 || k == 2*i) cout << "*";
                else cout << " ";
            }
        }
        cout <<"\n";
    }
}