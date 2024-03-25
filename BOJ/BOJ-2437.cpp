#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int n;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int res = 1;
    for(int i=0; i<n; i++){
        if(res < arr[i]){
            break;
        }
        res += arr[i];
    }
    cout << res;

}