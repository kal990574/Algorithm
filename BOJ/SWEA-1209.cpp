#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int> > v(100, vector<int>(100));
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cin >> v[i][j];
        }
    }

    vector<int> sum1(100, 0);
    vector<int> sum2(100, 0);
    int sum3 = 0;
    int sum4 = 0;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            sum1[i] += v[i][j];
        }
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            sum2[j] += v[i][j];
        }
    }

    for(int i=0; i<100; i++){
        sum3 += v[i][i];
    }

    for(int i=0; i<100; i++){
        sum4 += v[i][99-i];
    }

    int r1 = *max_element(sum1.begin(), sum1.end());
    int r2 = *max_element(sum2.begin(), sum2.end());
    int result = max(sum4, max(sum3, max(r1, r2)));
    cout << result;
}