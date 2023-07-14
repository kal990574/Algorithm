#include <iostream>
#include <string>
using namespace std;

int main(){
    int m,n;
    int white_cnt = 0;
    int black_cnt = 0;
    int result = 100;
    int min = 0;
    cin >> m >> n;

    char arr[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    char white_arr[8][8] = {
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W'
    };

    char black_arr[8][8] = {
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B'
    };

    for(int i=0; i<m-7; i++){
        for(int j=0; j<n-7; j++){
            for(int k=0; k<8; k++){
                for(int l=0; l<8; l++){
                    if(arr[i+k][j+l] != white_arr[k][l]) {
                        white_cnt++;
                    }
                    if(arr[i+k][j+l] != black_arr[k][l]) {
                        black_cnt++;
                }
                }
            }
            min = white_cnt < black_cnt ? white_cnt : black_cnt;
            white_cnt = 0;
            black_cnt = 0;
            result = min < result ? min : result;
        }
    }
    cout << result << "\n";
}