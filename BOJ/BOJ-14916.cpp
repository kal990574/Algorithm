#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt =0;
    if(n==1 || n==3) cout << "-1";
    else{
        while(n > 0){
            if(n%5==0){
            n -= 5;
            cnt ++;
        }
        else{
            n -= 2;
            cnt ++;
        }
    }
    cout << cnt;
    }
}