#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int cnt = 0;
    cin >> n;
    int tmp;
    cin >> tmp;
    int input;
    priority_queue<int> pq;
    if(n==1) cout << "0";
    else{
        for(int i=0; i<n-1; i++){
            cin >> input;
            pq.push(input);
        }
        while(pq.top() >= tmp){
                int q = pq.top() - 1;
                pq.pop();
                pq.push(q);
                tmp++;
                cnt++;
        }
        cout << cnt;
    }
    
}