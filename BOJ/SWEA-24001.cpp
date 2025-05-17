#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    int point = 0;
    int q_point = 0;
    int res = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'L'){
            point--;
        }
        if(str[i] == 'R'){
            point++;
        }
        if(str[i] == '?'){
            q_point++;
        }
        res = max(max(res, abs(point + q_point)), abs(point - q_point));
    }
    cout << res;
}