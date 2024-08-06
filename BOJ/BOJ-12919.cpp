#include <bits/stdc++.h>
using namespace std;
string S;
string T;
int recursive(string R){
    if(R == S) return 1;
    if(R.length() < S.length()) return 0;
    int res = 0;
    if(R[R.length() - 1] == 'A'){
        R.pop_back();
        res = max(res, recursive(R));
        R.push_back('A');
    }
    if(R[0] == 'B'){
        reverse(R.begin(), R.end());
        R.pop_back();
        res = max(res, recursive(R));
    }
    return res;
}
int main(){
    // S -> T
    // S 문자열 뒤 A 추가 -> T 문자열 뒤 A 빼기
    // or
    // S 문자열 뒤 B 추가 후 문자열 뒤집기 -> T 문자열 뒤집기 후 문자열 뒤 B 빼기
    // reverse(T.begin(), T.end());
    // T -> S로 만들 수 있으면 1 or 0
    cin >> S;
    cin >> T;
    cout << recursive(T);
}