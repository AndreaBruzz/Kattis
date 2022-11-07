// https://open.kattis.com/contests/r932dy/problems/cardmagic

#include <iostream>
using namespace std;

int N,T,K;
int dp[101][5001]; //numero mazzo - numero somma
const int MOD = 1000000009;
int main(){

    cin>>N>>K>>T;

    for(int i=1;i<=K;++i) dp[0][i] = 1;

	for(int i=1;i<N;++i){
		for(int j=i+1;j<=(i+1)*K;++j){
			for(int k=1;k<=K && j-k>0;++k){
				dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
			}
		}
	}

	cout<<dp[N-1][T]<<endl;

    return 0;
}