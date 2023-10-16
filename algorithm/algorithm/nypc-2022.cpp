#include <bits/stdc++.h>
using namespace std;
 
int N, M;
 
void no(){ puts("NO"); exit(0); }
 
int main()
{
    scanf("%d%d", &N, &M);
    vector<int> last_start_time(N+1, -1);
    for (int i=1;i<=M;i++){
        int ts, n, t; scanf("%d%d%d", &ts, &n, &t);
        if (t == 0){
            if (last_start_time[n] != -1) no();
            last_start_time[n] = ts;
        }else{
            if (last_start_time[n] == -1) no();
            if (ts-last_start_time[n] < 60) no();
            last_start_time[n] = -1;
        }
    }
    for (int i=1;i<=N;i++){
        if (last_start_time[i] != -1) no();
    }
    puts("YES");
}