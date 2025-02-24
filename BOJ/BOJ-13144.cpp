#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    //연속한 1개 이상 수 뽑을 때 같은 수가 여러번 등장하지 않는 경우의 수를 구하라.
    //1억회, 3200만 bytes
    // N <= 100,000
    // 투포인터?
    cin >> N;
    vector<int> v(N);
    long ans = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    int start = 0;
    int end = 1;
    set<int> s;
    s.insert(v[start]);
    ans += 1;

    while(end < N){
        int prev = s.size();

        s.insert(v[end]);

        if(prev != s.size()){
            //cout << start << " " << end << "\n";
            ans += (end - start + 1);
            end++;
        }

        if(prev == s.size()){
            end = start + s.size();
            s.erase(v[start]);
            start++;
        }
    }
    cout << ans << "\n";
}