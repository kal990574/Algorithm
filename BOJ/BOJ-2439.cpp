#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int k=n-i; k>1; k--){
            cout << " ";
        }
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        cout << "\n";
    }
}