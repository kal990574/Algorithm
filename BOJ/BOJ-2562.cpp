#include <iostream>
using namespace std;

int main()
{
    int arr[9];
    int max = 0;
    int tmp = 0;
    for(int i=0; i<9; i++){
        cin >> arr[i];
        if(max<=arr[i]){
            max = arr[i];
            tmp = i+1;
        }
    }
    cout << max;
    cout << "\n";
    cout << tmp;
}