#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    int K;
    cin >> T;
    while(T--){
        string str;
        vector<vector<int> > alpha(26);
        cin >> str >> K;
        int len = str.size();
        int len3 = 10001;
        int len4 = -1;

        for(int i=0; i<len; i++){
            alpha[str[i] - 'a'].push_back(i);
        }

        for(int i=0; i<26; i++){
            if(alpha[i].size() < K) continue;

            for(int j=0; j<alpha[i].size() - K + 1; j++){
                int len = alpha[i][j+K-1] - alpha[i][j] + 1;
                // cout << len << " " << alpha[i][j+K-1] << " " << alpha[i][j] << "\n";
                len3 = min(len3, len);
                len4 = max(len4, len);
            }

        }

        if(len3 == 10001) {
            cout << "-1" << "\n";
        }
        else{
            cout << len3 << " " << len4 << "\n";
        }
    }
}