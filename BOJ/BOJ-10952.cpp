#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    vector<int> v;
    while(1){
        cin >> a >> b;
         if(a == 0 && b == 0) break;
        v.push_back(a+b);
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}
