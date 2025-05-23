#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    for(int i=0; i<8; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int mn = 1;
    while(q.back() > 0){
        int fr = q.front();
        q.pop();

        fr -= mn;
        if(fr < 0) fr = 0;
        q.push(fr);
        mn++;
        if(mn == 6) mn = 1;
    }
    for(int i=0; i<8; i++){
        cout << q.front() << " ";
        q.pop();
    }
}