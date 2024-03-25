#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    cin >> s >> t;
    while(s.length()!=t.length()){
        char tmp = t[t.length()-1];
        if(tmp=='A'){
            t.pop_back();
        }
        if(tmp=='B'){
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
    if(s==t) cout << "1";
    else cout << "0";
}