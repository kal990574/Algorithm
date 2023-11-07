#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long dp[1001] = {0, };
    dp[1] = 1;
    dp[2] = 2; 
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n] % 10007 ;
}