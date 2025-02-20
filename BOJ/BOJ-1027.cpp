#include <bits/stdc++.h>
using namespace std;
int N;
double a, b;
int main(){
    cin >> N;
    vector<int> v(N+1);
    vector<int> apart(N+1, 2);
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }
    if(N == 1){
        cout << "0";
        return 0;
    }
    if(N == 2){
        cout << "1";
        return 0;
    }
    apart[1] = 1;
    apart[N] = 1;
    for(int i=1; i<N; i++){
        for(int j=i+2; j<=N; j++){
            int cnt = 0;
            a = double(v[i] - v[j])/(i-j); 
            b = v[i] - a*i;
            for(int k=i+1; k<j; k++){
                double y = a*k + b;
                if(v[k] < y) cnt ++;
                //cout << i << " " << j << "\n";
                //apart[i] ++;
                //apart[j] ++;
                if(k == j-1){
                    if(cnt == j-i-1){
                        //cout << i << " " << j << "\n";
                        apart[i] ++;
                        apart[j] ++;
                    }
                }
            }
        }
    }
    sort(apart.begin(), apart.end());
    cout << apart[N] << "\n";
}