#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    int odd_num = 0;
    int even_num = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
        if(v[i] % 2 == 0) even_num++;
        else odd_num++;
    }
    int wrong_odd = 0;
    int wrong_even = 0;
    for(int i=0; i<even_num; i++){
        if(v[i] % 2 != 0) wrong_odd++;
    }
    for(int i=even_num; i<N; i++){
        if(v[i] % 2 == 0) wrong_even++;
    }
    cout << min(wrong_odd, wrong_even) << "\n";
}