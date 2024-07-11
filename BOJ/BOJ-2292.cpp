#include <bits/stdc++.h>
using namespace std;
int dest;
int dept = 1;
int main(){
    cin >> dest;
    int res = 0;
    int cnt = 0;
    while(1){
        dept += (6 * cnt);
        res ++;
        if(dept >= dest) break;
        cnt ++;
    }
    cout << res;
}