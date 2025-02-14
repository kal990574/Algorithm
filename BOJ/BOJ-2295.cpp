#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int arr[1001];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    set<int> s;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            int tmp = arr[i] + arr[j];
            s.insert(tmp);
        }
    }
    sort(arr, arr+N);
    for(int k=N-1; k>0; k--){
        for(int j=k-1; j>=0; j--){
            if(s.count(arr[k] - arr[j])){
                cout << arr[k] << "\n";
                return 0;
            }
        }
    }
}