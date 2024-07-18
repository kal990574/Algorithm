#include <bits/stdc++.h>
using namespace std;
string str;
bool chk_vowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    else return false;
}
bool check(string input){
    int len = input.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i=0; i<len; i++){
        if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u') cnt1++;
        if(chk_vowel(input[i])){
            cnt3 = 0;
            cnt2++;
            if(cnt2 == 3) return false;
        }
        if(!chk_vowel(input[i])){
            cnt2 = 0;
            cnt3++;
            if(cnt3 == 3) return false;
        }
        if(i != len-1 && input[i] == input[i+1]){
            if(input[i] == 'e' || input[i] == 'o') continue;
            else return false;
        }
    }
    if(cnt1) return true;
    else return false;
}
int main(){
    while(1){
        cin >> str;
        if(str == "end") break;

        bool res = check(str);
        if(res) printf("<%s> is acceptable.\n", str.c_str());
        else printf("<%s> is not acceptable.\n", str.c_str());
    }
}