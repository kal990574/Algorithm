#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin >> a >> b;
    int c = max(a,b);
    int d = min(a,b);
	int e = c % d;
	while (e != 0) {
		c = d;
		d = e;
		e = c % d;
	}
    for(int i=0; i<d; i++){
        cout << "1";
    }
}