#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        dq.push_back(i);
    }

    for(int i=0; i<N; i++){
        cout << dq.front() << " ";
        dq.pop_front();
        int tmp = dq.front();
        dq.push_back(tmp);
        dq.pop_front();
    }
}