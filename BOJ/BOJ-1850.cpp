#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin >> a >> b;
    long long c = max(a,b);
    long long d = min(a,b);
	long long e = c % d;
	while (e != 0) {
		c = d;
		d = e;
		e = c % d;
	}
    for(int i=0; i<d; i++){
        cout << "1";
    }
}