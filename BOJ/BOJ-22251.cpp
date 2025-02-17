#include <bits/stdc++.h>
using namespace std;
int N,K,P,X;
set<int> res;
int change[10][10] = {
    {0,4,3,3,4,3,2,3,1,2}, //0
    {4,0,5,3,2,5,6,1,5,4}, //1
    {3,5,0,2,5,4,3,4,2,3}, //2
    {3,3,2,0,3,2,3,2,2,1}, //3
    {4,2,5,3,0,3,4,3,3,2}, //4
    {3,5,4,2,3,0,1,4,2,1}, //5
    {2,6,3,3,4,1,0,5,1,2}, //6
    {3,1,4,2,3,4,5,0,4,3}, //7
    {1,5,2,2,3,2,1,4,0,1}, //8
    {2,4,3,1,2,1,2,3,1,0} //9
};
void hoseok(int n, int k, int p, string x){
    if(p < 0) return;
    if(k == K) return;
    //cout << p;
    int target = x[k] - '0';
    //cout << target << "\n";

    for(int i=0; i<10; i++){
        //cout << i;
        if(change[target][i] <= p){
            x[k] = i + '0';
            int nn = stoi(x);
            if(nn <= n){
                //cout << nn << "\n";
                res.insert(nn);
            }
            hoseok(n, k + 1, p - change[target][i], x);
            x[k] = target + '0';
        }
    }
}

int main(){
    cin >> N >> K >> P >> X;
    string x_str = to_string(X);
    int tmp = K - x_str.size();
    for(int i=0; i<tmp; i++){
        x_str.insert(0, "0");
    }
    //cout << x_str;
    hoseok(N, 0, P, x_str);
    res.erase(X);
    res.erase(0);
    cout << res.size() << "\n";
}