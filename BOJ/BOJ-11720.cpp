#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int tmp = 0;
    for(int i=0; i<N;i++){
        tmp += s[i] - '0';
    }
    cout << tmp;
}