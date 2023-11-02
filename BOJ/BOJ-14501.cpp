#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int *T = new int[N+1];
    int *P = new int[N+1];
    int *dp = new int[N+1];
    for(int i=0; i<N; i++){
        cin >> T[i] >> P[i];
    }
    for(int i=N-1; i>=0; i--){
        if(i+T[i] > N){
        dp[i] = dp[i+1];
        }
        else{
        dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
        }
    }
    cout << dp[0];
    delete[] T;
    delete[] P;
    delete[] dp;
}