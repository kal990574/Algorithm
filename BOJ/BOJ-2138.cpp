#include <bits/stdc++.h>
using namespace std;
int N;
int res = 0;
string in, go;
vector<int> init(100001);
vector<int> goal(100001);

void toggle(int idx, vector<int>& tmp){
    if(idx == 0){
        tmp[idx] ^= 1;
        tmp[idx + 1] ^= 1;
    }
    else if(idx == N-1){
        tmp[idx] ^= 1;
        tmp[idx - 1] ^= 1;
    }
    else{
        tmp[idx] ^= 1;
        tmp[idx - 1] ^= 1;
        tmp[idx + 1] ^= 1;
    }
}

int greedy(bool firstbulb){
    int cnt = 0;
    vector<int> tmp = init;
    if(firstbulb == true){
        toggle(0, tmp);
        cnt ++;
    }
    //cout << tmp[0] << tmp[1] << tmp[2] << firstbulb << "\n";
    for(int i=1; i<N; i++){
        //cout << tmp[i-1] << goal[i-1] << "\n";
        if(tmp[i-1] != goal[i-1]){
            toggle(i, tmp);
            //cout << i << "\n";
            cnt ++;
        }
    }
    //cout << cnt;
    //cout << init[0] << init[1] << init[2] << "\n";
    if(tmp == goal) return cnt;
    else return INT_MAX;
}

int main(){
    cin >> N;
    cin >> in;
    cin >> go;

    for(int i=0; i<N; i++){
        init[i] = in[i] - '0';
        goal[i] = go[i] - '0';
    }

    res = min(greedy(true), greedy(false));

    if(res == INT_MAX) cout << -1;
    else cout << res;
}