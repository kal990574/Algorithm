#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int res =0;
    for(int i=1; i<n+1; i++){
        res += i;
    }
    cout << res;
}