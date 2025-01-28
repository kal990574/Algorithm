#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        if(str == "end") break;
        char maps[3][3];
        int num_x = 0;
        int num_o = 0;
        int num_d = 0;
        int end_cnt = 0;
        for(int i=0; i<9; i++){
            maps[i/3][i%3] = str[i];
            if(str[i] == 'X') num_x++;
            if(str[i] == 'O') num_o++;
            if(str[i] == '.') num_d++;
        }

        if(num_x != num_o && num_x != num_o + 1) {
            cout << "invalid" << "\n";
            continue;
        }
        
        if(maps[0][0] != '.' && maps[0][0] == maps[0][1] && maps[0][1] == maps[0][2]){
            end_cnt ++;
        }
        if(maps[1][0] != '.' && maps[1][0] == maps[1][1] && maps[1][1] == maps[1][2]){
            end_cnt ++;
        }
        if(maps[2][0] != '.' && maps[2][0] == maps[2][1] && maps[2][1] == maps[2][2]){
            end_cnt ++;
        }
        ///
        if(maps[0][0] != '.' && maps[0][0] == maps[1][0] && maps[1][0] == maps[2][0]){
            end_cnt ++;
        }
        if(maps[0][1] != '.' && maps[0][1] == maps[1][1] && maps[1][1] == maps[2][1]){
            end_cnt ++;
        }
        if(maps[0][2] != '.' && maps[0][2] == maps[1][2] && maps[1][2] == maps[2][2]){
            end_cnt ++;
        }
        ///
        if(maps[0][0] != '.' && maps[0][0] == maps[1][1] && maps[1][1] == maps[2][2]){
            end_cnt ++;
        }
        if(maps[0][2] != '.' && maps[0][2] == maps[1][1] && maps[1][1] == maps[2][0]){
            end_cnt ++;
        }
        ///
        if(end_cnt > 1){
            cout << "invalid" << "\n";
            continue;
        }

        if(end_cnt == 0 && num_x + num_o != 9){
            cout << "invalid" << "\n";
            continue;
        }
        ///
        cout << "valid" << "\n";
    }
}