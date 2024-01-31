#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n,m;
    int k;
    cin >> n >> m;
    vector<vector<int> > maps(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
        }
    }

    cin >> k;

    vector<vector<int> > ran(k, vector<int>(4));
    for(int i=0; i<k; i++){
        for(int j=0; j<4; j++){
            cin >> ran[i][j];
            ran[i][j] -= 1;
        }
    }

    int res = 0;
    for(int i=0; i<k; i++){
        for(int j=ran[i][0]; j <= ran[i][2]; j++){
            for(int p=ran[i][1]; p <= ran[i][3]; p++){
                res += maps[j][p];
            }
        }
        cout << res << "\n";
        res = 0;
    }
}