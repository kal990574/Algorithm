#include <bits/stdc++.h>
using namespace std;
int test_case = 1;

int main(){
    int N;
        cin >> N;
        vector<int> v(N);
        long long res = 0;
        int mx = 0;
        for(int i=0; i<N; i++){
            cin >> v[i];
            mx = max(v[i], mx);
        }
        int mx = 0;
        for(int i=N-1; i>=0; i--){
        	mx = max(mx, v[i]);
            if(mx > v[i]){
                res += (mx-v[i]);
            }
        }
        cout << "#" << test_case << " " << res << "\n";
}