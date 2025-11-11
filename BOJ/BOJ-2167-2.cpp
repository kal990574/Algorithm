#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[301][301];
    int N,M;
    int sum[301][301];
    cin >> N >> M;
    for(int i=1; i<=N; i++){ // 0 ~ N-1
        for(int j=1; j<=M; j++){ // 0 ~ M-1
            cin >> arr[i][j];
            if(j>0) sum[i][j] = sum[i][j-1] + arr[i][j];
            else sum[i][j] = arr[i][j];
        }
    }
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int res = 0;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j=a; j<=c; j++){
            res += (sum[j][d] - sum[j][b-1]);
        }
        cout << res << "\n";
    }

}