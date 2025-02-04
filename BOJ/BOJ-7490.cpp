#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> ans;
bool isZero(string exp){
    vector<int> num;
    vector<char> cal;
    string tmp;
    for(int i=0; i<exp.size(); i++){
        if(exp[i] == '+' || exp[i] == '-'){
            num.push_back(stoi(tmp));
            cal.push_back(exp[i]);
            tmp = "";
        }
        else if(exp[i] != ' '){
            tmp.push_back(exp[i]);
        }
    }
    num.push_back(stoi(tmp));
    //cout << num[0] << " " << num[1] << " " << num[2] << "\n";

    int result = num[0];
    for(int i=0; i<cal.size(); i++){
        if(cal[i] == '+'){
            result += num[i+1];
        } 
        else if(cal[i] == '-'){
            result -= num[i+1];
        }
        //cout << result << "rs" << '\n';
    }

    if(result == 0) return true;
    else return false;
}
void makesZero(int cur, string exp){
    if(cur == N){
        if(isZero(exp)){
            ans.push_back(exp);
        }
        return;
    }
    makesZero(cur + 1, exp + '+' + to_string(cur+1));
    makesZero(cur + 1, exp + '-' + to_string(cur+1));
    makesZero(cur + 1, exp + ' ' + to_string(cur+1));
}

int main(){
    int T;
    int num[10];
    cin >> T;

    while(T--){
        cin >> N;
        makesZero(1, "1");
        sort(ans.begin(), ans.end());
        for(string str : ans){
            cout << str << "\n";
        }
        cout << "\n";
        ans.clear();
    }
    //sort()
}