#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

vector<pair<int,int> > path[10001];

int dp[12345];

int main(){
	for(int i=0; i<10001; i++) dp[i] = MAX;
	int N,D;
	int a,b,c;
	
	cin >> N >> D;
	for(int i=0; i<N; i++){
		cin >> a >> b >> c;
		path[a].push_back(make_pair(b,c));
	}
	
	dp[0] = 0;
	for(int i=0; i<=D; i++){
		dp[i+1] = min(dp[i+1], dp[i]+1);
		
		for(auto k : path[i]){
			dp[k.first] = min(dp[k.first], dp[i]+k.second);
		}
	}
	
	cout << dp[D];
	return 0;
}