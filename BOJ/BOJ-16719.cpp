#include <bits/stdc++.h>
using namespace std;
#define INF 999
string input;
bool arr[101];

void zoac(int start, int end){
    int min = INF;
    int idx = 0;

    for(int i=start; i<end; i++){
        if(!arr[i] && input[i] < min){
            min = input[i];
            idx = i;
        }
    }
        if(min == INF) return;
        arr[idx] = 1;
        for(int i=0; i<input.length(); i++){
            if(arr[i]) cout << input[i];
        }
        cout << "\n";
        zoac(idx + 1, end);
        zoac(start, idx);
}

int main(){
    cin >> input;
    zoac(0, input.length());
}