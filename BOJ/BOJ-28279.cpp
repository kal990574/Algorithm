#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; 
    cin >> N;
    
    int arr[2000001];
    int front = 1000000;   
    int back  = 1000000;  
    
    for(int i=0; i<N; i++){
        int cmd; 
        cin >> cmd;

        if (cmd == 1) {              
            int x; 
            cin >> x;
            front--;
            arr[front] = x;
        } 
        
        else if (cmd == 2) {      
            int x; 
            cin >> x;
            arr[back] = x;
            back++;
        } 
        
        else if (cmd == 3) {       
            if (front == back) cout << -1 << '\n';
            else{
                cout << arr[front] << '\n';
                front++;
            }
        } 
        
        else if (cmd == 4) {       
            if (front == back) cout << -1 << '\n';
            else{
                back--;
                cout << arr[back] << '\n';
            }
        } 
        
        else if (cmd == 5) {      
            cout << back - front << '\n';
        } 
        
        else if (cmd == 6) {       
            if(front == back) cout << 1 << '\n';
            else cout << 0 << '\n';
        } 
        
        else if (cmd == 7) {       
            if (front == back) cout << -1 << '\n';
            else cout << arr[front] << '\n';
        } 
        
        else if (cmd == 8) {       
            if (front == back) cout << -1 << '\n';
            else cout << arr[back - 1] << '\n';
        }
    }
}
