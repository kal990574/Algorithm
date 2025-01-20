#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string balls;
    cin >> balls;
    int R = 0;
    int B = 0;

    for(int i=0; i<balls.size(); i++){
        if(balls[i] == 'R') R++;
        if(balls[i] == 'B') B++;
    }

    int leftR = 0;
    int leftB = 0;
    int rightR = 0;
    int rightB = 0;

    for(int i=0; i<balls.size(); i++){
        if(balls[i] == 'R') leftR++;
        else break;
    }
    for(int i=0; i<balls.size(); i++){
        if(balls[i] == 'B') leftB++;
        else break;
    }
    for(int i=balls.size() - 1; i>=0; i--){
        if(balls[i] == 'R') rightR++;
        else break;
    }
    for(int i=balls.size() - 1; i>=0; i--){
        if(balls[i] == 'B') rightB++;
        else break;
    }

    int ans = 0;
    ans = min(min(min(R-leftR, R-rightR), B-leftB), B-rightB);
    cout << ans;
}