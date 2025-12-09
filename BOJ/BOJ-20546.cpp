#include <bits/stdc++.h>
using namespace std;
int main(){
    int seed;
    cin >> seed;

    int jhSeed = seed;
    int jhNum = 0;
    int smSeed = seed;
    int smNum = 0;
    int smCnt1 = 0;
    int smCnt2 = 0;

    vector<int> v(14);
    cin >> v[0];
    int t = jhSeed / v[0];
        if(t > 0){
            jhNum += t;
            jhSeed -= v[0] * t;
        }
    
    for(int i=1; i<14; i++){
        cin >> v[i];

        int tmp = jhSeed / v[i];
        if(tmp > 0){
            jhNum += tmp;
            jhSeed -= v[i] * tmp;
        }

        if(v[i] < v[i-1]){
            smCnt1++;
            if(smCnt1 >= 3){
                int tmp1 = smSeed / v[i];
                smNum += tmp1;
                smSeed -= v[i] * tmp1;
            }
            smCnt2 = 0;
        }
        else if(v[i] > v[i-1]){
            smCnt2++;
            if(smCnt2 >= 3){
                smSeed += smNum * v[i];
                smNum = 0;
            }
            smCnt1 = 0;
        }
        else{
            smCnt1 = 0;
            smCnt2 = 0;
        }
    }
    int jhRes = jhNum * v[13] + jhSeed;
    int smRes = smNum * v[13] + smSeed;

    if(jhRes > smRes) cout << "BNP";
    else if(jhRes < smRes) cout << "TIMING";
    else cout << "SAMESAME";
}