#include <bits/stdc++.h>
using namespace std;
int N, M;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    unordered_map<int, int> cards;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        cards[tmp] += 1;
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int sg;
        cin >> sg;
        if(cards.count(sg)){
            cout << cards[sg] << " ";
        }
        else cout << "0 ";
    }
}