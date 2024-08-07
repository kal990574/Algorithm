#include <bits/stdc++.h>
using namespace std;
int n, k;
int belt[201][2];

int main(){
    cin >> n >> k;
    for(int i=1; i<=2*n; i++){
        cin >> belt[i][1];
    }

    int phase = 1;
    while(1){
        int zero = 0;
        // step 1
        int tmp0 = belt[2*n][0];
        int tmp1 = belt[2*n][1];
        for(int i=2*n; i>=2; i--){
            if(i >= n){
                belt[i][0] = 0;
                belt[i][1] = belt[i-1][1];
            }
            else{
                belt[i][0] = belt[i-1][0];
                belt[i][1] = belt[i-1][1];
            }
        }
        belt[1][0] = tmp0;
        belt[1][1] = tmp1;
        
        // step 2
        for(int i=n; i>=1; i--){
            if(belt[i][0] == 1 && belt[i+1][0] == 0 && belt[i+1][1] != 0){
                belt[i][0] = 0;
                belt[i+1][0] = 1;
                belt[i+1][1] -=1;
            }
        }
        
        // step 3
        if(belt[1][0] == 0 && belt[1][1] != 0){
            belt[1][0] = 1;
            belt[1][1] -= 1;
        }

        // step 4
        for(int i=1; i<=2*n; i++){
            if(belt[i][1] == 0) zero += 1;
        }
        if(zero >= k) break;
        
        // end
        phase += 1;
    }
    cout << phase;
}