#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int res=0;
    cin >> N;
    vector<int> b(N);
    int arr[4] = {-2,-1,1,2};
    for(int i=0;i<N; i++){
        cin >> b[i];
    }
    for(int i=2; i<N-2; i++){
        int mx = 0;
        for(int j : arr){
            mx = max(mx, b[i+j]);
        }
        if(b[i] > mx) res += (b[i] - mx);
    }
    cout << res;
}