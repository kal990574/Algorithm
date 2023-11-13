#include <bits/stdc++.h>
using namespace std;
void hanoi(int n, int start, int end, int pass){
    if(n==1){
        cout << start << " " << end << "\n";
        }
    else {
        hanoi(n-1, start, pass, end);
        cout << start << " " << end << "\n";
        hanoi(n-1, pass, end, start);
    }
}
int n;
int main(){
    cin >> n;
    cout << (1<<n) - 1 << "\n";
    hanoi(n,1,3,2);
}