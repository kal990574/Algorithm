#include <bits/stdc++.h>
using namespace std;
string str;
string bomb;
vector<int> fir;
// maps<char>
int main(){
    cin >> str >> bomb;
    for(int i=0; i<str.size(); i++){
        if(str[i] == bomb[0]){
            fir.push_back(i);
        }
    }
    for(int i=0; i<fir.size(); i++){
        for(int j=fir[i]; j<fir[i] + bomb.size(); j++){
            if(str[j] == bomb[])
        }
    }
}