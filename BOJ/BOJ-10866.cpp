#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> dq;
    int N;
    int M;
    cin >> N;
    string req;
    for(int i=N; i>0; i--){
        cin >> req;
        if(req=="push_front"){
            cin >> M;
            dq.push_front(M);
        }

        if(req=="push_back"){
            cin >> M;
            dq.push_back(M);
        }

        if(req=="pop_front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else cout << -1 << "\n";
        }

        if(req=="pop_back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else cout << -1 << "\n";
        }

        if(req=="size"){
            cout << dq.size() << "\n";
        }

        if(req=="empty"){
            if(!dq.empty()){
                cout << "0" << "\n";
            }
            else cout <<"1" << "\n";
        }

        if(req=="front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
            }
            else cout << "-1" << "\n";
        }

        if(req=="back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
            }
            else cout << "-1\n";
        }
    }
}