#include <bits/stdc++.h>
using namespace std;
int N;
char maps[1001][1001];
int hrt[2];
int arm[2];
int mid;
int leg[2];
int cnt = 0;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> maps[i][j];
            if(maps[i][j] == '*' && cnt == 0){
                hrt[0] = i+1;
                hrt[1] = j;
                cnt ++;
            }
        }
    }

    for(int i=hrt[1]-1; i>=1; i--){
        if(maps[hrt[0]][i] == '*') arm[0]++;
        if(maps[hrt[0]][i] == '_') break;
    }
    for(int i=hrt[1]+1; i<=N; i++){
        if(maps[hrt[0]][i] == '*') arm[1]++;
        if(maps[hrt[0]][i] == '_') break;
    }
    for(int i=hrt[0]+1; i<=N; i++){
        if(maps[i][hrt[1]] == '*') mid++;
        if(maps[i][hrt[1]] == '_') break;
    }
    for(int i=hrt[0]+mid+1; i<=N; i++){
        if(maps[i][hrt[1]-1] == '*') leg[0]++;
        if(maps[i][hrt[1]-1] == '_') break;
    }
    for(int i=hrt[0]+mid+1; i<=N; i++){
        if(maps[i][hrt[1]+1] == '*') leg[1]++;
        if(maps[i][hrt[1]+1] == '_') break;
    }

    cout << hrt[0] << " " << hrt[1] << "\n";
    cout << arm[0] << " " << arm[1] << " " << mid << " " << leg[0] << " " << leg[1];

}