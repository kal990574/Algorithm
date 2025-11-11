#include <bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
    long ans = 0;
    long sum = 0;
    for(int i=1; i<=n-2; i++){
        sum += i;
        ans += sum;
    }
    cout << ans << "\n" << "3";
}