#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int arr[10] ={0,};
    int tmp = 0;
    cin >> a >> b >> c;
    int result;
    result = a * b * c;
    string str;
    str = to_string(result);
    int cnt = str.size();
    for(int i=0; i<cnt; i++){
        tmp = result%10;
        arr[tmp]++;
        result /= 10;
    }
    for(int j=0; j<10; j++){
        cout << arr[j];
        cout << "\n";
    }
}