#include <bits/stdc++.h>
using namespace std;
int main(){
    // 24분 42초
    // 실버 4
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        vector<int> pro(10001);
        int max = 0;
        int max_idx = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int tmp;
                cin >> tmp;
                pro[tmp]++;
                if(pro[tmp] > max){
                    max_idx = tmp;
                    max = pro[tmp];
                }
            }
        }
        int max2 = 0;
        for(int i=1; i<=10000; i++){
            if(i == max_idx) continue;
            if(pro[i] > max2) max2 = pro[i];
        }
        for(int i=1; i<=10000; i++){
            if(max2 == pro[i]){
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}