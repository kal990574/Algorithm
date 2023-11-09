#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000
ll N;
ll dp[102][10];

int main(){
    cin >> N;
    dp[1][0] = 0;
    dp[0][1] = 1;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            if(j==0) dp[i][j] = 0;
            else if(j==9) dp[i][j] = (dp[i-1][j-1]) % mod;
            else if(j==1) dp[i][j] = (dp[i-1][j+1] + dp[i-2][j]) % mod;
            else{
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
            } 
        }
    }
    ll res = 0;
    for(int i=0; i<10; i++){
        res += (dp[N][i])%mod;
    }
    cout << res % mod;
}