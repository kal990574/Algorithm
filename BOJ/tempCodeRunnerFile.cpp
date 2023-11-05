#include <iostream>
using namespace std;
int main(){
    int M,N,T;
    int res;
    for(int i=0; i<T; i++){
        cin >> N >> M;
        for(int j=0; j<N; j++){
            res *=M;
            M--;
        }
    }
}