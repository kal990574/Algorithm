#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int tmp = 0;
    for(int i=0; i<5; i++){
        cin >> arr[i];
        tmp = tmp + arr[i]*arr[i];
    }
    tmp %= 10;
    cout << tmp;
}