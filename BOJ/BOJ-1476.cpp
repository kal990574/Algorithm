#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int E,M,S;
    cin >> E >> M >> S;
    int i = 0;
    int A,B;
    int res;
    while(1){
        res = M + 28*i;
        A = res%15;
        B = res%19;
        if(A == 0) A = 15;
        if(B == 0) B = 19;
        if(A == E && B == S) break;
        i++;
    }
    cout << res;
}