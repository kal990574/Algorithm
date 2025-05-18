#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A;
    vector<int> B;
    vector<char> res(N+1, '?');
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    for(int i=0; i<N; i++){
        int b;
        cin >> b;
        B.push_back(b);
    }

    int flag = 1;
    for(int i=0; i<N; i++){
        if(flag == 1){
            res[A[0]] = 'A';
            for(int j=0; j<B.size(); j++){
                if(B[j] == A[0]) B.erase(B.begin()+j);
            }
            A.erase(A.begin());
        }

        else{
            res[B[0]] = 'B';
            for(int j=0; j<A.size(); j++){
                if(A[j] == B[0]) A.erase(A.begin()+j);
            }
            B.erase(B.begin());
        }

        if(flag == 1) flag = 2;
        else flag = 1;
    }
    res.erase(res.begin());
    for(char ch : res){
        cout << ch;
    }


}