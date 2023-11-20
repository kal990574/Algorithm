#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a,b,c,d;
long long res;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for(int i=0;i<t; i++){
        vector<int> v;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> c;
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        for(int j=0; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                a = v[j];
                b = v[k];
                while(1){
                d = b % a;
                b = a;
                a = d;
                if(a==0) break;
                }
                res += b; 
            }
        }
        cout << res << "\n";
        res = 0;
    }
}