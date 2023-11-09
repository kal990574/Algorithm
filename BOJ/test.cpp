#include <vector>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    vector<int>::iterator it = v.begin();
    v.insert(it, 2, 4);
    cout << v[0] <<v[1];
    v[0] = 3;
    cout << v[0];
}