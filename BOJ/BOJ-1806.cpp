#include <bits/stdc++.h>
using namespace std;
int N, S;
int arr[100001];
int main(){
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int start = 0;
    int end = 0;
    int min_cnt = INT_MAX;
    int sum = 0;
    while(end <= N){
        int cnt = end - start;
        //cout << start << " " << end << "\n";
        if(sum >= S){
            min_cnt = min(min_cnt, cnt);
            sum -= arr[start];
            start++;
        }
        else{
            sum += arr[end];
            end ++;
        }
    }
    if(min_cnt == INT_MAX) cout << 0;
    else{
        cout << min_cnt << "\n";
    }
}