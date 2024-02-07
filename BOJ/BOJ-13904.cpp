#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &v1, pair<int, int> &v2) {
	if (v1.second == v2.second) {
		return v1.first > v2.first; 
	}
	else return v1.second > v2.second; 
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    int d,w;
    vector<int> plan(1002);
    int res = 0;
    for(int i=0; i< n; i++){
        cin >> d >> w;
        v.push_back(make_pair(d,w));
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++){
        for(int j=v[i].first; j>0; j--){
            if(!plan[j]){
                plan[j] = v[i].second;
                res += plan[j];
                break;
            }
        }
    }
    cout << res;
    return 0;
}