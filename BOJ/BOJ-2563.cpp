#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int n;

int main(){
    cin >> n;
    int cnt =0;
    vector<vector<int> > v(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
    }
    for(int i=0; i<n; i++){
        int x = v[i][0];
        int y = v[i][1];
        for(int j = x; j<x+10; j++){
            for(int k =y; k<y+10; k++){
                if(arr[j][k] == 0)
                    cnt ++;
                arr[j][k] = 1;
            }
        }
    }
    cout << cnt;
}