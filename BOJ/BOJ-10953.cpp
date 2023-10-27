#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    int T;
    vector<int> v;
    cin >> T;
    for(int i=0; i<T; i++){
        scanf("%d,%d", &a, &b);
        v.push_back(a+b);
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}
