#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    int N;
    cin >> N;
    int arr[10001] = {0,};
    int tmp =0;
    for(int i=0; i<N; i++){
        cin >> tmp;
        arr[tmp]++;
    }
    for(int i=1; i<10001; i++){
        if(arr[i]>0){
            for(int j=0; j<arr[i]; j++){
            cout << i << "\n";
            }
        }
    }
}