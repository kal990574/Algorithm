#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> h(N+1);
    vector<int> left(N+1, 0);
    vector<int> right(N+1, 0);
    vector<int> nearest(N+1, -100000);
    for(int i=1; i<=N; i++){
        cin >> h[i];
    }
    stack<int> st1;
    for(int i=1; i<=N; i++){
        while(!st1.empty()){
            int topIdx = st1.top();
            int topHeight = h[st1.top()];
            if(topHeight <= h[i]){
                st1.pop();
            }
            else{
                break;
            }
        }
        if(!st1.empty()){
            left[i] += st1.size();
            nearest[i] = st1.top();
        }
        st1.push(i);
    }

    stack<int> st2;
    for(int i=N; i>=1; i--){
        while(!st2.empty()){
            int topIdx = st2.top();
            int topHeight = h[st2.top()];
            if(topHeight <= h[i]){
                st2.pop();
            }
            else{
                break;
            }
        }
        if(!st2.empty()){
            right[i] += st2.size();
            if(i - nearest[i] > st2.top() - i){
                nearest[i] = st2.top();
            }
        }
        st2.push(i);
    }

    for(int i=1; i<=N; i++){
        if(left[i] + right[i] == 0){
            cout << "0\n";
        }
        else cout << left[i] + right[i] << " " << nearest[i] << "\n";
    }
}