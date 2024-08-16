#include <bits/stdc++.h>
using namespace std;
int N;
int tower[500000];
int res[500000];
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tower[i];
    }
    for(int i=N; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            if(tower[i] <= tower[j]){
                res[i] = j+1;
                break;
            }
        }
    }
    for(int i=0; i<N; i++){
        cout << res[i];
    }
}