#include <bits/stdc++.h>
using namespace std;
int main(){
    int mon, day;
    cin >> mon >> day;
    vector<int> month;
    month.push_back(31);
    month.push_back(28);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    month.push_back(30);
    month.push_back(31);
    int tmp = 0;
    for(int i=0; i<mon-1; i++){
        tmp += month[i];
    }
    tmp += day;
    if(tmp%7==1) cout<< "MON";
    if(tmp%7==2) cout<< "TUE";
    if(tmp%7==3) cout<< "WED";
    if(tmp%7==4) cout<< "THU";
    if(tmp%7==5) cout<< "FRI";
    if(tmp%7==6) cout<< "SAT";
    if(tmp%7==0) cout<< "SUN";
}