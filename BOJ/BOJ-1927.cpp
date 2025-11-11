#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    priority_queue<long long, vector<long long>, greater<>> pq;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        long long tmp;
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()){
                cout << "0" << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(tmp);
        }
    }
}