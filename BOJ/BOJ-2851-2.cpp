#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum = 0;
    int prev = 0;
    for(int i=0; i<10; i++){
        int tmp = 0;
        cin >> tmp;
        sum += tmp;
        if(sum >= 100){
            if(abs(100-sum)<=100-prev){
                cout << sum;
            }
            else cout << prev;
            break;
        }
        prev = sum;
    }
    if(sum < 100) cout << sum;
}