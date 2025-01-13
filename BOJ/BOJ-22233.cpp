#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    cin.ignore();
    set<string> s;
    for(int i=0; i<N; i++){
        string str1;
        cin >> str1;
        s.insert(str1);
    }
    cin.ignore();
    for(int i=0; i<M; i++){
        string str2;
        getline(cin, str2);

        stringstream ss(str2);
        string word;
        while(getline(ss, word, ',')){
            if(s.count(word)){
                s.erase(word);
            }
        }
        cout << s.size() << "\n";
    }
}