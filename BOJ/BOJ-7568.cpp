#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int rank = 1;
    vector<vector<int> > v(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][0] < v[j][0] && v[i][1] < v[j][1]) rank++;
        }
        cout << rank << " ";
        rank = 1; 
    }
}