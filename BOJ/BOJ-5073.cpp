#include <bits/stdc++.h>
using namespace std;
int tri[3];
int tmp;
int main(){
    while(1){
        for(int i=0; i<3; i++){
        cin >> tri[i];
    }
    if(tri[0] == 0 && tri[1] == 0 && tri[2] == 0) break;
        sort(tri, tri+3);
        if(tri[2] >= (tri[0] + tri[1])){
            cout << "Invalid";
    }
        else {
            if(tri[0] == tri[1] && tri[1] == tri[2]) cout << "Equilateral";
            else if(tri[0] == tri[1] || tri[1] == tri[2] || tri[0] == tri[2]) cout << "Isosceles";
            else cout << "Scalene";
    }
    cout << "\n";
    }
}