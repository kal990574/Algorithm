#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    int guilder_count = 0;
    int k = 0;
    int res = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    cin >> guilder_count;
    cin >> k;
    deque<int> dq;
    for(int i=0; i<N; i++){
        dq.push_back(v[i]);
    }
    for(int i=0; i<guilder_count; i++){
        int sz = dq.size();
        int max_val = -1;
        int max_idx = -1;
        int erase = 0;
        for(int i=0; i<min(k,sz); i++){
            if(max_val < dq[i]){
                max_val = dq[i];
                max_idx = i;
            }
        }
        for(int i=sz-1; i>=sz-min(k,sz); i--){
            if(max_val < dq[i]){
                max_val = dq[i];
                max_idx = i;
            }
        }
        if(max_idx < sz - max_idx){
            vector<int> temp;
            for(int i=0; i<max_idx; i++){
                int front = dq.front();
                dq.pop_front();
                temp.push_back(front);
            }
            erase = dq.front();
            dq.pop_front();
            for(int i=temp.size()-1; i>=0; i--){
                dq.push_front(temp[i]);
            }
        }
        else{
            vector<int> temp;
            for(int i=0; i<sz - max_idx - 1; i++){
                int back = dq.back();
                dq.pop_back();
                temp.push_back(back);
            }
            erase = dq.back();
            dq.pop_back();
            for(int i=temp.size()-1; i>=0; i--){
                dq.push_back(temp[i]);
            }
        }
        res += erase;
    }
    cout << res << "\n";
}