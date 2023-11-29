#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    float res = 0;
    float k = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        float num = 0;
        cin >> num;
        string grd;
        cin >> grd;
        float g;
        if(grd == "A+") g = 4.3;
        if(grd == "A0") g = 4.0;
        if(grd == "A-") g = 3.7;
        if(grd == "B+") g = 3.3;
        if(grd == "B0") g = 3.0;
        if(grd == "B-") g = 2.7;
        if(grd == "C+") g = 2.3;
        if(grd == "C0") g = 2.0;
        if(grd == "C-") g = 1.7;
        if(grd == "D+") g = 1.3;
        if(grd == "D0") g = 1.0;
        if(grd == "D-") g = 0.7;
        if(grd == "F") g = 0.0;
        res += num * g;
        k += num;
    }
    float result = 0;
    result = res/k;
    printf("%0.2f", result);
}