#include <bits/stdc++.h>
using namespace std;
int P;
int stu[1001][21];
int res[1001] = {0, };
int num;
int main(){
    cin >> P;
    while(P){
        cin >> num;
        for(int i=1; i<21; i++){
            cin >> stu[num][i];
            for(int j=1; j<i; j++){
                if(stu[num][j] > stu[num][i]){
                    for(int k=j; k<i; k++){
                        swap(stu[num][j], stu[num][k+1]);
                        res[num]++;
                    }
                    break;
                }
            }
        }
        P--;
    }
    for(int i=1; i<num+1; i++){
        cout << i << " " << res[i] << "\n";
    }
}