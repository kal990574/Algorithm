#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    queue<int> q;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;

        if(str=="push"){
            int a;
            cin >> a;
            q.push(a);
        }

        if(str=="pop"){
            if(!q.empty()){
            cout << q.front() << "\n";
            q.pop();
            }
            else cout << "-1\n";
        }

        if(str=="size"){
            cout << q.size() << "\n" ;
        }

        if(str=="front"){
            if(q.empty()) cout<< "-1\n";
            else cout << q.front() << "\n";
        }

        if(str=="back"){
            if(q.empty()) cout <<"-1\n";
            else cout << q.back() << "\n";
        }

        if(str=="empty"){
            if(!q.empty()) cout << "0\n";
            if(q.empty()) cout << "1\n";
        }
    }
}