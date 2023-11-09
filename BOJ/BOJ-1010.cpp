#include <iostream>
using namespace std;
int main(){
    int T;
    double res;
    double M,N;
    int tmp;
    cout << "Enter :";
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> M;
        res = 1;
        tmp = N;
        for(int j=0; j<tmp; j++){
            res *=M;
            res /=N;
            M--;
            N--;
        }
        cout << (int)res << "\n";
    }
}