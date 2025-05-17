#include <bits/stdc++.h>
using namespace std;
int main(){
    int test_case = 1;
    string str;
    cin >> str;
    int res = 0;
    for(int i=1; i<=10; i++){
        string pat = str.substr(0,i);
        string com = str.substr(i, i);
        string com2 = str.substr(2*i, i);
        if(pat == com && com == com2){
            res = pat.size();
            break;
        }
    }
    cout << res;
}