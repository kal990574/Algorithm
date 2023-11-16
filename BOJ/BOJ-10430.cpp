#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int r1,r2,r3,r4;
    r1 = (A+B)%C;
    r2 = ((A%C) + (B%C))%C;
    r3 = (A*B)%C;
    r4 = ((A%C)*(B%C))%C;
    cout << r1 <<"\n" << r2 <<"\n" << r3 <<"\n" << r4 <<"\n";
}