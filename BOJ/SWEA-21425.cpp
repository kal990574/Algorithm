#include <bits/stdc++.h>
using namespace std;
int test_case = 1;
int main(){
    int A,B,N;
    cin >> A >> B >> N;
    int cnt = 1;
    while(A+B<=N){
        if(A < B){
            A += B;
        }
        else B += A;
        cnt ++;
    }
    cout << cnt;
}