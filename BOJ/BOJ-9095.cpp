#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    int dp[1000000];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int m=0;
    int N[11];
    N[0] = 0;
    for(int i=1; i<T+1; i++){
        cin >> N[i];
        m = max(N[i], m);
    }        
    for(int j=4; j< m+1; j++){
        dp[j]= dp[j-1] + dp[j-2] + dp[j-3];
    }
    for(int i=1; i<T+1; i++){
        cout << dp[N[i]] << "\n";
    }
}