#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int N = 0;
    int B = 0;
    int tmp = 0;
    deque<int> v;
    string s = "";
    cin >> N >> B;
    while(1){
        tmp = N%B;
        v.push_front(tmp);
        N = N / B;
        if(N == 0) break;
    }
    for(int i=0; i<v.size(); i++){
        if(v[i] < 10){
            s += (char)(v[i] + '0');
        }
        else {
            s += (char)(v[i] -10 + 'A');
        }
    }
    cout << s;
}