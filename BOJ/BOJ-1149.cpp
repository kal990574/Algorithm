#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int dp[1003][3];
    int RGB[1003][3];
    int *R = new int[N];
    int *G = new int[N];
    int *B = new int[N];
    for(int i=0; i<N; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
        dp[i][j] = min(dp[i-1][j]+RGB[i-1][j])
        }
    }
}