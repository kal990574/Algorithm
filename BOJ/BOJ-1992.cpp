#include <bits/stdc++.h>
using namespace std;

int dp[65][66];
int n;

int isSame(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(dp[x][y]!=dp[i][j]) return false;
        }
    }
    return true;
}
void QuadTree(int x, int y, int n){
    if(isSame(x,y,n)){
        cout << dp[x][y];
    }
    else{
        n /= 2;
        cout << "(";
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                QuadTree(x + i*n ,y + j*n ,n);
            }
        }
        cout << ")";
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
            string S; cin >> S;
            for(int j=0; j<S.length(); j++){
                dp[i][j] = S[j] - '0';
            }
    }
    QuadTree(0,0,n);
}