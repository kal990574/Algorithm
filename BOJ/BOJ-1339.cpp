#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> alpha(26);
    int res = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i=0; i<v.size(); i++){
        int pow = 1;
        for(int j=v[i].size() - 1; j>=0; j--){
            int val = v[i][j] - 'A';
            alpha[val] += pow;
            pow *= 10;
        }
    }
    sort(alpha.begin(), alpha.end());
    int num = 9;
    for(int i=25; i>=0; i--){
        if(!alpha[i]) break;
        res += (alpha[i]*num);
        num--;
    }
    cout << res << "\n";
}