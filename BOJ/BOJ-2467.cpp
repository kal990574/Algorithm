#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int liq[100001];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> liq[i];
    }
    int start = 0;
    int end = N - 1;
    int res = INT_MAX;
    int res_s = 0;
    int res_e = 0;
    while(start<end){
        int mix = liq[start] + liq[end];
        int tmp = min(res, abs(mix));
        if(mix == 0){
            res_s = start;
            res_e = end;
            break;
        }
        if(tmp != res){
            res = tmp;
            res_s = start;
            res_e = end;
        }
        if(mix > 0) end--;
        if(mix < 0) start++;
    }
    cout << liq[res_s] << " " << liq[res_e];
}