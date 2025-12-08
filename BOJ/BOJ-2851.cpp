#include <bits/stdc++.h>
using namespace std;
int main(){
    // 1억회, 1억 2800만 bytes
    int sum = 0;
    int cur = 0;
    int prev = INT_MAX;
    int res = 0;

    for(int i=0; i<10; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;

        cur = 100 - sum;

        if(abs(cur) <= abs(prev)) res = sum;

        prev = cur;
    }
    cout << res << "\n";
}