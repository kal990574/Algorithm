#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main(){
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        int a = str[i];
        a = a - '0';
        if(a == 6 || a == 9) a = 6;
        m[a] += 1;
    }

    if(m[6]%2 == 1) m[6] = m[6]/2 + 1;
    else m[6] = m[6]/2;

    int mx = 0;
    for(auto i : m){
        mx = max(mx, i.second);
    }
    cout << mx;
}