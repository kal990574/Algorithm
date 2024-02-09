#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int t;
    int n;
    cin >> t;
    int a, b;
    int idx = 0;
    int res = 1;
    for(int i=0; i<t; i++){
        idx = 0;
        res = 1;
        cin >> n;
        vector<pair<int, int> > v;
        for(int j=0; j<n; j++){
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(), v.end());

        for(int k=1; k<n; k++){
            if(v[k].second < v[idx].second){
                res++;
                idx = k;
            }
        }
        cout << res << "\n";
    }
}