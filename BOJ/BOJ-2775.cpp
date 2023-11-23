#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int arr[15][15];
    for(int i=0; i<T; i++){
        int n,k;
        cin >> n >> k;
        for(int j=1; j<=k; j++){
            arr[0][j] = j;
        }
        for(int j = 1; j<=n; j++){
            arr[j][1] = 1;
        }
        for(int j=1; j<= n; j++){
            for(int l=2; l <= k; l++){
                arr[j][l] = arr[j][l-1] + arr[j-1][l];
            }
        }
        cout << arr[n][k] << '\n';
    }
}