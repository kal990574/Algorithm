#include <bits/stdc++.h>
using namespace std;
int N;
stack<pair<int, int> > stk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        int tmp;
        cin >> tmp;
        while(!stk.empty()){
            if(stk.top().second > tmp){
                cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        if(stk.empty()){
            cout << "0 ";
        }
        stk.push(make_pair(i, tmp));
    }
}