#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    string S;
    cin >> S;
    int cnt[2] ={0,};
    int res = 100;
    if(S[0]=='0'){
        S=S+'0';
        for(int i=0; i<S.size(); i++){
        if(S[i]=='0' && S[i+1]=='1') cnt[0]++;
        if(S[i]=='1' && S[i+1]=='0') cnt[1]++;
        }
    }
    if(S[0]=='1'){
        S=S+'1';
        for(int i=0; i<S.size(); i++){
        if(S[i]=='0' && S[i+1]=='1') cnt[0]++;
        if(S[i]=='1' && S[i+1]=='0') cnt[1]++;
        }
    }
    res = min(cnt[0], cnt[1]);
    cout << res;
    // cout << "\n" << S << "\n" << cnt[0] << "\n" << cnt[1];
}