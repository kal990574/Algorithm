#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int t;
    int a,b;
    cin >> t;
    vector<int> v;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        v.push_back(a+b);
    }
    for(int i=0; i<t; i++){
        cout << v[i] << "\n";
    }
}
