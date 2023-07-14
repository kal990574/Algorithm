#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    while(1){
        cin >> a;

        if(a.compare("0") == 0) break;
        if(a.size() == 1) cout << "yes\n";
        for(int i=0; i<a.size()/2; i++){
            if(a[i] != a[a.size()-1-i]){
                cout << "no\n";
                break;
            }
            if(i == a.size()/2 - 1) cout << "yes\n";
        }
    }
}