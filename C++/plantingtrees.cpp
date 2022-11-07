//https://open.kattis.com/contests/e4htpf/problems/plantingtrees

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int N;
	cin>>N;
	
	int v[N];
	for(int i=0; i<N; i++) cin>>v[i];
	sort(v,v+N,greater<int>());
	
	int gt=v[0];
	for(int i=1; i<N; i++){
		gt--;
		if(gt < v[i]) gt = v[i];
	}
	
	cout<<N+gt+1;
	
	return 0;
}