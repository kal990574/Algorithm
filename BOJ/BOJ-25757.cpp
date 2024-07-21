#include <bits/stdc++.h>
using namespace std;
int N;
char ch;
int main(){
    set<string> s;
    cin >> N >> ch;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    if(ch=='Y') cout << (s.size()/1);
    if(ch=='F') cout << (s.size()/2);
    if(ch=='O') cout << (s.size()/3);
}
