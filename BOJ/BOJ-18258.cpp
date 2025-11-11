#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    // N <= 2,000,000
    int front = 0;
    int back = 0;
    int arr[2000001];
    for(int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            arr[back] = x;
            back++;
        }
        else if(cmd == "pop"){
            if(front == back){
                cout << "-1" << "\n";
            }
            else{
                cout << arr[front] << "\n";
                front++;
            }
        }
        else if(cmd == "size"){
            cout << back - front << "\n";
        }
        else if(cmd == "empty"){
            if(front == back){
                cout << "1" << "\n";
            }
            else{
                cout << "0" << "\n";
            }
        }
        else if(cmd == "front"){
            if(front == back){
                cout << "-1" << "\n";
            }
            else{
                cout << arr[front] << "\n";
            }
        }
        else if(cmd == "back"){
            if(front == back){
                cout << "-1" << "\n";
            }
            else{
                cout << arr[back-1] << "\n";
            }
        }
    }

}