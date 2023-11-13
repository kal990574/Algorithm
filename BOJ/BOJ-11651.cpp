#include <bits/stdc++.h>
using namespace std;
int N;

int main(){
    cin >> N;
    vector< pair<int,int> > arr(N);
    int x, y;
    for(int i=0; i<N; i++){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<N; i++){
        cout << arr[i].second << " " << arr[i].first <<"\n";
    }
}