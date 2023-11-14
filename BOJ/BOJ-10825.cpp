#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int kor, eng, mat;
};
bool compare(student a, student b){
    if(a.kor == b.kor){
        if(a.eng == b.eng){
            if(a.mat == b.mat){
                return a.name < b.name;
            }
            else return a.mat > b.mat;
        }
        else return a.eng < b.eng;
    }
    else return a.kor > b.kor;
}

int main(){
    int N;
    cin >> N;
    int k,e,m;
    vector<student> s(N);
    for(int i=0; i<N; i++){
        cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].mat;
    }
    sort(s.begin(), s.end(), compare);
    for(int i=0; i<N; i++){
        cout << s[i].name << "\n";
    }
}