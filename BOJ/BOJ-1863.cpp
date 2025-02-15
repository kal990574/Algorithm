#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    stack<int> s;
    int res = 0;
    int zero = 0;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if(y == 0) zero = 1;
        while(!s.empty() && s.top() > y){
            res++;
            s.pop();
        }
        if(s.empty() || s.top() < y){
            s.push(y);
        }
        //cout << s.top();
    }
    res += s.size();
    res -= zero;
    cout << res;
}