/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int dx[4] = {-1,1,0,0};
int H,W;
int dy[4] = {0,0,-1,1}; //U D L R
bool Chk(int x, int y){
    if(x<0 || x>=H || y<0 || y>=W){
        return false;
    }
    return true;
}
void Shooting(vector<string>& maps, char direction, int tx, int ty){
    int idx = 0;
    if(direction == 'v') idx = 1;
    if(direction == '<') idx = 2;
    if(direction == '>') idx = 3;
    if(direction == '^') idx = 0;
    while(1){
        tx += dx[idx];
        ty += dy[idx];
        if(Chk(tx, ty)){
            if(maps[tx][ty] == '*'){
                maps[tx][ty] = '.';
                return ;
            }
            if(maps[tx][ty] == '#'){
                return ;
            }
        }
        else return;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        string com;
        cin >> H >> W;
        vector<string> maps(H);
        int tx, ty;
        for(int i=0; i<H; i++){
            cin >> maps[i];
            for(int j=0; j<W; j++){
                if(maps[i][j] == '<' || maps[i][j] == '>' || maps[i][j] == 'v' || maps[i][j] == '^'){
                    tx = i;
                    ty = j;
                }
            }
        }
        cin >> N;
        cin >> com;
        for(int i=0; i<N; i++){
            if(com[i] == 'U'){
                maps[tx][ty] = '^';
                if(Chk(tx-1, ty)){
                    if(maps[tx-1][ty] == '.'){
                        maps[tx][ty] = '.';
                        maps[tx-1][ty] = '^';
                        tx -=1;
                    }
                }
            }
            if(com[i] == 'D'){
                maps[tx][ty] = 'v';
                if(Chk(tx+1, ty)){
                    if(maps[tx+1][ty] == '.'){
                        maps[tx][ty] = '.';
                        maps[tx+1][ty] = 'v';
                        tx+=1;
                    }
                }
            }
            if(com[i] == 'L'){
                maps[tx][ty] = '<';
                if(Chk(tx, ty-1)){
                    if(maps[tx][ty-1] == '.'){
                        maps[tx][ty] = '.';
                        maps[tx][ty-1] = '<';
                        ty -=1;
                    }
                }
            }
            if(com[i] == 'R'){
                maps[tx][ty] = '>';
                if(Chk(tx, ty+1)){
                    if(maps[tx][ty+1] == '.'){
                        maps[tx][ty] = '.';
                        maps[tx][ty+1] = '>';
                        ty+=1;
                    }
                }
            }
            if(com[i] == 'S'){
                Shooting(maps, maps[tx][ty], tx, ty);
            }
        }
        cout << "#" << test_case << " ";
        for(int i=0; i<H; i++){
            cout << maps[i] << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}