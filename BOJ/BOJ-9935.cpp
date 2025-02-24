#include <bits/stdc++.h>
using namespace std;
string str;
string bomb;
vector<int> fir;
stack<char> s;
// maps<char>
//입력받으면서 stack에 넣으며 폭팔 판정
int main(){
    cin >> str >> bomb;
    for(int i=str.size()-1; i>str.size()-bomb.size(); i--){
        s.push(str[i]);
        //cout << str[i];
    }
    for(int i=str.size()-bomb.size(); i>=0; i--){
        string tmp;
        s.push(str[i]);
        for(int j=0; j<bomb.size(); j++){
            if(!s.empty()){
                tmp += s.top();
                s.pop();
            }
            if(j == bomb.size() - 1 && tmp != bomb){
                for(int k=tmp.size()-1; k>=0; k--){
                    s.push(tmp[k]);
                }
            } 
        }
    }
    string ans;
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    if(ans.empty()){
        cout << "FRULA";
    }
    else cout << ans;
}