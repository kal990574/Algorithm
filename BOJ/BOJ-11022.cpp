#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin >> T;
    int A,B;
    vector<int> v;
    for(int i=0; i<T; i++){
        cin >> A >> B;
        printf("Case #%d: %d + %d = %d\n", i+1, A, B, A+B);
    }
}