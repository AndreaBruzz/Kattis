// https://open.kattis.com/contests/r932dy/problems/increasingsubsequence

#include <bits/stdc++.h>
using namespace std;

vector<int> max(vector<int> a, vector<int> b){
	if(a.size() > b.size()) return a;

	if(a.size() == b.size() && a < b) return a;

	return b;
}

int main(){
	
	int n;
	cin >> n;

	while(n){

		vector<int> nums(n), dp[n],mam;
		
		for(int i=0; i<n; i++){
			cin>>nums[i];
		}
		
		for(int i=0; i<n; i++){
			vector<int> tmp;
			for(int j=0; j<i; j++){
				if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]);
			}
			dp[i].push_back(nums[i]);
			mam = max(mam,dp[i]);
		}

		cout<<mam.size()<<" ";
		for(int i=0; i<mam.size(); i++) cout<<mam[i]<<" ";
		cout<<endl;
		cin>>n;
	}
	
	return 0;
}
