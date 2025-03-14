#include<bits/stdc++.h>
using namespace std;
int main(){
    // 단축키 지정
    // 단어별로 확인
    // 단어 확인 이후 왼쪽에서부터 알파벳 별 확인
    // 대 -> 소 +32, 소 -> 대 -32
    int N;
    cin >> N;
    cin.ignore();

    vector<string> word;
    for(int i=0; i<N; i++){
        string str;
        getline(cin, str);
        word.push_back(str);
    }

    set<char> s;

    for(int i=0; i<N; i++){
        int idx = 0;
        int idx1 = 0;

        string tmp = word[i];
        istringstream ss (tmp);
        string subs;
        vector<string> v;

        while(getline(ss, subs, ' ')){
            v.push_back(subs);
        }

        int set_size = s.size();
        for(int j=0; j<v.size(); j++){
            if(!s.count(v[j][0])){
                s.insert(v[j][0]);
                s.insert(v[j][0] + 32);
                s.insert(v[j][0] - 32);
                idx = idx1;
                break;
            }
            idx1 += (v[j].size()+1);
        }

        if(set_size == s.size()){
            for(int j=0; j<word[i].size(); j++){
                if(word[i][j] != ' ' && !s.count(word[i][j])){
                    s.insert(word[i][j]);
                    s.insert(word[i][j] - 32);
                    s.insert(word[i][j] + 32);
                    idx = j;
                    break;
                }
                else continue;
            }
        }

        if(set_size == s.size()){
            cout << word[i] << "\n";
            continue;
        }

        for(int j=0; j<idx; j++){
            cout << word[i][j];
        }
        cout << "[" << word[i][idx] << "]";
        for(int j=idx+1; j<word[i].size(); j++){
            cout << word[i][j];
        }
        cout << "\n";
    }
}