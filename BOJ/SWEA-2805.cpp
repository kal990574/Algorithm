#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int result = 0;
    vector<vector<int> > v(N, vector<int>(N));
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<N; j++){
            int tmp = str[j] - '0';
            v[i][j] = tmp;
        }
    }

    for(int i=0; i<N/2; i++){
        for(int j=N/2-i; j<=N/2+i; j++){
            result += v[i][j];
        }
    }

    for(int i=0; i<N; i++){
        result += v[N/2][i];
    }
    int k=2;
    for(int i=N/2+1; i<N; i++){
        for(int j=i-N/2; j<=N-k; j++){
            result += v[i][j];
        }
        k++;
    }
    cout << result;
}