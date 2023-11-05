#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int X;
    cin >> X;
    int cnt = 0;
    while(1){
        if(X%2 == 1){
            cnt ++;
        }
        X /= 2;
        if(X <= 0) break;
    }
    cout << cnt;
}