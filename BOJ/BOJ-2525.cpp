#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, m;
    cin >> h >> m;
    int d;
    cin >> d;
    m += d;
    int tmp = m/60;
    h += tmp;
    m %= 60;
    if(h >= 24){
        h -= 24;
    }
    cout << h << " " << m;
}