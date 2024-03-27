#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5][5];
    vector<vector<int> > v(5, vector<int>(5));
    vector<int> v1(5);
    int arr1[5];
    arr[0][0] = 1;
    arr1[0] = 1;
    v[0][0] = 1;
    v1[0] = 1;

    // 2차원 배열 초기화 -> memset()
    cout << "2d arr\n";
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << arr[i][j] << " "; 
        }
        cout << "\n";
    }

    // 2차원 벡터 초기화 -> fill()
    cout << "\n";
    cout << "2d vec\n";    
    fill(v.begin(), v.end(), vector<int>(5,0));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << v[i][j] << " "; 
        }
        cout << "\n";
    }

    // clear() 시 형태만 남김
    // v1.clear();
    // 1차원 벡터 초기화 -> fill()
    fill(v1.begin(), v1.end(), 0);
    cout << "\n";
    cout << "1d vec\n";
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }

    // 1차원 배열 초기화 -> memset()
    memset(arr1, 0, sizeof(arr1));
    cout << "\n";
    cout << "1d arr\n";
    for(int i=0; i<5; i++){
        cout << arr1[i] << " ";
    }
}