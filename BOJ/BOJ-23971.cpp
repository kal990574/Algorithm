#include <bits/stdc++.h>
using namespace std;
int H,W,N,M;
int main(){
    cin >> H >> W >> N >> M;
    int x = 1;
    int y = 1;
    int cnt_x = 0;
    int cnt_y = 0;
    while(y <= H){
        cnt_y ++;
        y += (N+1);
    }
    while(x <= W){
        cnt_x ++;
        x += (M+1);
    }
    int res = cnt_x * cnt_y;
    cout << res;
}