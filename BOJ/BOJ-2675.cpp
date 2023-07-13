#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R;
        string S;
        cin >> R >> S;

        string P = "";
        for (int k = 0; k < S.size(); k ++) {
            char c = S[k];
            for (int j = 0; j < R; j++) {
                P += c;
            }
        }

        cout << P << endl;
    }

    return 0;
}