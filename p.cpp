#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v(10, 2);
    for(int i=0; i<10; i++){
        v[i] = i;
    }
    v.erase(v.begin() + 2);
    v.insert(v.begin()+2, 5);
    for(int s : v){
        cout << s << "\n";
    }
}