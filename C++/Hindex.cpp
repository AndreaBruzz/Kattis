// https://open.kattis.com/problems/hindex

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int check(int r){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(v[i]>=r) cnt++;
	}
	return cnt;
}

int main(){
	
	cin>>n;
	v = vector<int>(n);
	for(int i=0; i<n; i++) cin>>v[i];	
	
	//Bin Search
	int f=0, l=n;
	int mid;
	
	while(f<l){
		mid = f + (l-f+1)/2;
		if(check(mid)>=mid) f = mid;
		else l = mid-1;
	}
	cout<<f<<endl;
	return 0;
}
