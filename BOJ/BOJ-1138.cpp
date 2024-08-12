#include <bits/stdc++.h>
using namespace std;
int N;
int arr[11];
vector<int> v;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i=N; i>=1; i--){
        int tmp = arr[i];
        v.insert(v.begin()+tmp, i);
    }
    for(int i=0; i<N; i++){
        cout << v[i] << " ";
    }
}