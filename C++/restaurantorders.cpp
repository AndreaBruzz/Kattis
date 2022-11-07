// https://open.kattis.com/contests/r932dy/problems/orders

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
vector<ll> c,s;
ll dp[30001], bt[30001];
int main(){

    cin>>n;
    ll tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        c.push_back(tmp);
    }

    cin>>m;

    dp[0] = 1;

    for(int j=0;j<n;++j){
		for(int i=c[j];i<30001;++i){
			dp[i] += dp[i-c[j]];
			if(dp[i]==1 && dp[i-c[j]]==1)
				bt[i] = j;
		}
    }

    while(m>0){

        ll x;
		cin>>x;
		if(dp[x]==0)
			cout<<"Impossible";
		else if(dp[x]>1)
			cout<<"Ambiguous";
		else{
			vector<ll> ans;
			int j = x;
			while(j>0){
				ans.push_back(bt[j]);
				j -= c[bt[j]];
			}
			reverse(ans.begin(),ans.end());

			for(ll a: ans)
				cout<<a+1<<' ';
			cout<<endl;
		}
		
        cout<<endl;

        m--;
    }
    return 0;
}