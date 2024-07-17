#include <bits/stdc++.h>
using namespace std;
int N;
int K;
struct nation {
    int idx;
    int gold; 
    int silver;
    int bronze;
    int score;
};
nation arr[1001];

bool cmp(nation a, nation b){
    if(a.gold > b.gold) return true;
    else if(a.gold == b.gold) {
        if(a.silver > b.silver) return true;
        else if(a.silver == b.silver) {
            if(a.bronze > b.bronze) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i].idx;
        cin >> arr[i].gold;
        cin >> arr[i].silver;
        cin >> arr[i].bronze;
    }
    sort(arr, arr+N, cmp);
    int sc = 0;
    for(int i=0; i<N; i++){
        sc = 1;
        for(int j=0; j<i; j++){
            if(arr[i].gold == arr[j].gold && arr[i].silver == arr[j].silver && arr[i].bronze == arr[j].bronze) continue;
            sc++;
        }
        arr[i].score = sc;
    }
    for(int i=0; i<N; i++){
        if(arr[i].idx == K) cout << arr[i].score;
    }

}