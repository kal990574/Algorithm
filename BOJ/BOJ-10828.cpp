#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> stk;
    int N;
    cin >> N;
    string res;
    for(int i=0; i<N; i++){
        cin >> res;

        if(res == "push"){
            int K;
            cin >> K;
            stk.push(K);
        }

        if(res == "pop"){
            if(stk.empty()) cout << "-1" << "\n";
            else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        }

        if(res == "size"){
            cout << stk.size() << "\n";
        }

        if(res == "empty"){
            if(stk.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }

        if(res == "top"){
            if(stk.empty()) cout << "-1" << "\n";
            else {
                cout << stk.top() << "\n";
            }
        }

    }
}