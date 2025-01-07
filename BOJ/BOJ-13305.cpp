#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int road[100001];
    int price[100001];
    long long answer = 0;
    cin >> N;
    for(int i=0; i < N-1; i++){
        cin >> road[i];
    }
    for(int i=0; i < N; i++){
        cin >> price[i];
    }
    int min_price = INT_MAX;
    for(int i=0; i<N-1; i++){
        min_price = min(min_price, price[i]);
        answer += (long long)(min_price) * road[i];
    }
    cout << answer;
}