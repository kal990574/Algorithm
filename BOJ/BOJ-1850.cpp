#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int a,b;
    int mul = a * b;
    cin >> a >> b;
    int c = max(a,b);
    int d = min(a,b);
	int e = c % d;
	while (e != 0) {
		c = d;
		d = e;
		e = c % d;
	}
    cout << d;
}