#include <bits/stdc++.h>
using namespace std;
int N, C;
int main(){
    // 이분탐색
    // 파라메트릭 서치
    // 매개변수 탐색 -> 목표 값을 정해두고 탐색
    cin >> N >> C;
    vector<int> home(N);
    vector<vector<int> > dp(N, vector<int>(2));
    for(int i=0; i<N; i++){
        cin >> home[i];  
    }
    sort(home.begin(), home.end());
    int start = 1;
    int end = home[N-1] - home[0];
    //int start_index = 0;
    //int end_index = N;
    int mid = (home[start]+home[end])/2;
    int pivot = 0;
    C-=1;
    int h = C;
    int res = 0;
    while(start <= end){
        int ori = h;
        int mid = (start+end) / 2;
        // 설치
        for(int i=pivot; i<N; i++){
            if(home[i] >= home[pivot] + mid){
                pivot = i;
                h -= 1;
                //cout << "mid:" << mid <<" pivot:" << pivot << " res:" << res << " h:" << h << "\n";
                break;
            }
        }
        // 설치 모두 완료
        if(h == 0){
            //cout << "H" << "\n";
            res = max(res, mid);
            start = mid + 1;
            pivot = 0;
            h = C;
        }

        // 설치 실패
        else if(ori == h){
            end = mid - 1;
            h = C;
            pivot = 0;
        }
    }
    cout << res << "\n";
}