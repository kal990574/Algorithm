#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[1000001];
    // 스택 구현
    int cmd;
    int top = -1;
    for(int i=0; i<N; i++){
        cin >> cmd;
        if(cmd == 1){
            int x;
            cin >> x;
            top++;
            arr[top] = x;
        }

        else if(cmd == 2){
            if(top == -1){
                cout << "-1" << "\n";
            }
            else{
                cout << arr[top] << "\n";
                top--;
            }
        }

        else if(cmd == 3){
            cout << top + 1 << "\n";
        }

        else if(cmd == 4){
            if(top == -1){
                cout << "1" << "\n";
            }
            else{
                cout << "0" << "\n";
            }
        }

        else if(cmd == 5){
            if(top == -1){
                cout << "-1" << "\n";
            }
            else{
                cout << arr[top] << "\n";
            }
        }
    }
}