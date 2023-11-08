#include <bits/stdc++.h>
using namespace std;
int arr[3000][3000];
int tmp;
int res[3];

int isSame(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[x][y]!=arr[i][j]) return false;
        }
    }
    return true;
}
void Search(int x, int y, int n){
    if(isSame(x,y,n)){
        res[arr[x][y]+1]++;
    }
    else {
        n /= 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Search(x + i*n,y + j*n ,n);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i< N; i++){
        for(int j=0; j<N; j++){
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    Search(0,0, N);
    for(int i=0; i<3; i++){
        cout << res[i] << "\n";
    }
}